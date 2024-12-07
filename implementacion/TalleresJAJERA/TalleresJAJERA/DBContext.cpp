#include "DBContext.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;


// Habilitamos el uso del namespace std
using namespace std;

// Definición de los atributos estáticos de la clase DBContext.
// Cambiar estos valores en función de la DB a la que te quieras conectar
string DBContext::Host = "database-minipim.cdwgeayaeh1v.eu-central-1.rds.amazonaws.com:3306";
string DBContext::User = "grupo07";
string DBContext::Password = "FjLWM6DNk6TJDzfV";
string DBContext::Database = "grupo07DB";

// Constructor por defecto: inicializa los atributos con las credenciales estáticas.
DBContext::DBContext()
    : driver(nullptr) {
    if (!connect()) { // Llama a connect() dentro del constructor
        throw runtime_error("No se pudo conectar a la base de datos al inicializar DBContext");
    }
}

// Destructor: Cierra la conexión si está abierta antes de destruir la instancia.
DBContext::~DBContext() {
    if (connection) {
        connection->close();
    }
}

System::String^ DBContext::ConvertToUTF8(const std::string& input) {
    // Crear un array de bytes del tamaño adecuado
    auto bytes = gcnew cli::array<unsigned char>(input.size());

    // Llenar el array de bytes con los caracteres de la cadena
    for (size_t i = 0; i < input.size(); ++i) {
        bytes[i] = static_cast<unsigned char>(input[i]);
    }

    // Convertir el array de bytes a un System::String usando UTF-8
    return System::Text::Encoding::UTF8->GetString(bytes);
}

string DBContext::ConvertFromUTF8(System::String^ input) {
    // Convertir System::String^ (UTF-16) a un arreglo de bytes en UTF-8
    auto bytes = System::Text::Encoding::UTF8->GetBytes(input);

    // Crear un std::string desde los bytes
    std::string result(bytes->Length, '\0');
    for (int i = 0; i < bytes->Length; ++i) {
        result[i] = static_cast<char>(bytes[i]);
    }

    return result;
}


// Método para establecer una conexión con la base de datos.
// Usa el driver de MySQL para conectarse al host especificado con las credenciales.
// Devuelve `true` si la conexión fue exitosa; de lo contrario, `false`.
bool DBContext::connect() {
    try {
        driver = get_driver_instance(); // Obtiene la instancia del driver de MySQL.
        connection = unique_ptr<sql::Connection>(
            driver->connect("tcp://" + Host, User, Password)); // Conecta al host con las credenciales.
        connection->setSchema(Database); // Establece el esquema (base de datos).
        
        // Configura la conexión para usar UTF-8
        unique_ptr<sql::Statement> stmt(connection->createStatement());
        stmt->execute("SET NAMES 'utf8mb4'");
        stmt->execute("SET CHARACTER SET 'utf8mb4'");

        cout << "Conexión establecida con éxito.\n";
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "Error de conexión: " << e.what() << endl;
        return false;
    }
}

// Método para cerrar la conexión con la base de datos.
// Devuelve `true` si la operación fue exitosa; de lo contrario, `false`.
bool DBContext::close() {
    try {
        if (connection) {
            connection->close(); // Cierra la conexión si está abierta.
            cout << "Conexión cerrada exitosamente.\n";
        }
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "Error al cerrar la conexión: " << e.what() << endl;
        return false;
    }
}

// Método para realizar una consulta `SELECT` y devolver los resultados.
// Devuelve un vector de vectores, donde cada sub-vector representa una fila de resultados.
vector<vector<string>> DBContext::select(const string& query) {
    vector<vector<string>> results;
    try {
        unique_ptr<sql::Statement> stmt(connection->createStatement()); // Crea un statement.
        unique_ptr<sql::ResultSet> res(stmt->executeQuery(query)); // Ejecuta la consulta.

        // Itera sobre los resultados de la consulta.
        while (res->next()) {
            vector<string> row;
            for (int i = 1; i <= res->getMetaData()->getColumnCount(); i++) {
                row.push_back(res->getString(i)); // Agrega cada columna al vector.
            }
            results.push_back(row); // Agrega la fila completa al resultado final.
        }
    }
    catch (sql::SQLException& e) {
        cerr << "Error en SELECT: " << e.what() << endl;
    }
    return results; // Devuelve los resultados obtenidos.
}

// Método para ejecutar una consulta que no devuelva resultados (`INSERT`, `UPDATE`, etc.).
// Devuelve el número de filas afectadas o `-1` si hubo un error.
int DBContext::execute(const string& query) {
    try {
        unique_ptr<sql::Statement> stmt(connection->createStatement()); // Crea un statement.
        return stmt->executeUpdate(query); // Ejecuta la consulta.
    }
    catch (sql::SQLException& e) {
        cerr << "Error en la ejecución de consulta: " << e.what() << endl;
        return -1; // Indica que hubo un error.
    }
}

// Método para eliminar filas de una tabla específica según una condición.
// Construye la consulta `DELETE` y utiliza el método `execute` para ejecutarla.
// Devuelve el número de filas afectadas o `-1` si hubo un error.
int DBContext::deleteRow(const string& table, const string& condition) {
    try {
        string query = "DELETE FROM " + table + " WHERE " + condition; // Construye la consulta.
        return execute(query); // Ejecuta la consulta usando el método `execute`.
    }
    catch (sql::SQLException& e) {
        cerr << "Error al ejecutar DELETE: " << e.what() << endl;
        return -1; // Indica que hubo un error.
    }
}
