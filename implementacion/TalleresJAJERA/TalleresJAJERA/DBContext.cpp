#include "DBContext.h"
#include <iostream>


// Habilitamos el uso del namespace std
using namespace std;

// Definici�n de los atributos est�ticos de la clase DBContext.
string DBContext::Host = "database-minipim.cdwgeayaeh1v.eu-central-1.rds.amazonaws.com:3306";
string DBContext::User = "grupo07";
string DBContext::Password = "FjLWM6DNk6TJDzfV";
string DBContext::Database = "grupo07DB";

// Constructor por defecto: inicializa los atributos con las credenciales est�ticas.
DBContext::DBContext()
    : driver(nullptr) {
    if (!connect()) { // Llama a connect() dentro del constructor
        throw runtime_error("No se pudo conectar a la base de datos al inicializar DBContext");
    }
}

// Destructor: Cierra la conexi�n si est� abierta antes de destruir la instancia.
DBContext::~DBContext() {
    if (connection) {
        connection->close();
    }
}

// M�todo para establecer una conexi�n con la base de datos.
// Usa el driver de MySQL para conectarse al host especificado con las credenciales.
// Devuelve `true` si la conexi�n fue exitosa; de lo contrario, `false`.
bool DBContext::connect() {
    try {
        driver = get_driver_instance(); // Obtiene la instancia del driver de MySQL.
        connection = unique_ptr<sql::Connection>(
            driver->connect("tcp://" + Host, User, Password)); // Conecta al host con las credenciales.
        connection->setSchema(Database); // Establece el esquema (base de datos).
        cout << "Conexi�n establecida con �xito.\n";
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "Error de conexi�n: " << e.what() << endl;
        return false;
    }
}

// M�todo para cerrar la conexi�n con la base de datos.
// Devuelve `true` si la operaci�n fue exitosa; de lo contrario, `false`.
bool DBContext::close() {
    try {
        if (connection) {
            connection->close(); // Cierra la conexi�n si est� abierta.
            cout << "Conexi�n cerrada exitosamente.\n";
        }
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "Error al cerrar la conexi�n: " << e.what() << endl;
        return false;
    }
}

// M�todo para realizar una consulta `SELECT` y devolver los resultados.
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

// M�todo para ejecutar una consulta que no devuelva resultados (`INSERT`, `UPDATE`, etc.).
// Devuelve el n�mero de filas afectadas o `-1` si hubo un error.
int DBContext::execute(const string& query) {
    try {
        unique_ptr<sql::Statement> stmt(connection->createStatement()); // Crea un statement.
        return stmt->executeUpdate(query); // Ejecuta la consulta.
    }
    catch (sql::SQLException& e) {
        cerr << "Error en la ejecuci�n de consulta: " << e.what() << endl;
        return -1; // Indica que hubo un error.
    }
}

// M�todo para eliminar filas de una tabla espec�fica seg�n una condici�n.
// Construye la consulta `DELETE` y utiliza el m�todo `execute` para ejecutarla.
// Devuelve el n�mero de filas afectadas o `-1` si hubo un error.
int DBContext::deleteRow(const string& table, const string& condition) {
    try {
        string query = "DELETE FROM " + table + " WHERE " + condition; // Construye la consulta.
        return execute(query); // Ejecuta la consulta usando el m�todo `execute`.
    }
    catch (sql::SQLException& e) {
        cerr << "Error al ejecutar DELETE: " << e.what() << endl;
        return -1; // Indica que hubo un error.
    }
}
