#include "DBContext.h"
#include <iostream>

// Definición de los atributos estáticos de la clase DBContext.
std::string DBContext::Host = "database-minipim.cdwgeayaeh1v.eu-central-1.rds.amazonaws.com:3306?auth_plugin=mysql_native_password";
std::string DBContext::User = "grupo07";
std::string DBContext::Password = "FjLWM6DNk6TJDzfV";
std::string DBContext::Database = "grupo07DB";

// Constructor por defecto: inicializa los atributos con las credenciales estáticas.
DBContext::DBContext()
    : driver(nullptr) {
    if (!connect()) { // Llama a connect() dentro del constructor
        throw std::runtime_error("No se pudo conectar a la base de datos al inicializar DBContext");
    }
}

// Destructor: Cierra la conexión si está abierta antes de destruir la instancia.
DBContext::~DBContext() {
    if (connection) {
        connection->close();
    }
}

// Método para establecer una conexión con la base de datos.
// Usa el driver de MySQL para conectarse al host especificado con las credenciales.
// Devuelve `true` si la conexión fue exitosa; de lo contrario, `false`.
bool DBContext::connect() {
    try {
        driver = get_driver_instance(); // Obtiene la instancia del driver de MySQL.
        connection = std::unique_ptr<sql::Connection>(
            driver->connect("tcp://" + Host, User, Password)); // Conecta al host con las credenciales.
        connection->setSchema(Database); // Establece el esquema (base de datos).
        std::cout << "Conexión establecida con éxito.\n";
        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error de conexión: " << e.what() << std::endl;
        return false;
    }
}

// Método para cerrar la conexión con la base de datos.
// Devuelve `true` si la operación fue exitosa; de lo contrario, `false`.
bool DBContext::close() {
    try {
        if (connection) {
            connection->close(); // Cierra la conexión si está abierta.
            std::cout << "Conexión cerrada exitosamente.\n";
        }
        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error al cerrar la conexión: " << e.what() << std::endl;
        return false;
    }
}

// Método para realizar una consulta `SELECT` y devolver los resultados.
// Devuelve un vector de vectores, donde cada sub-vector representa una fila de resultados.
std::vector<std::vector<std::string>> DBContext::select(const std::string& query) {
    std::vector<std::vector<std::string>> results;
    try {
        std::unique_ptr<sql::Statement> stmt(connection->createStatement()); // Crea un statement.
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(query)); // Ejecuta la consulta.

        // Itera sobre los resultados de la consulta.
        while (res->next()) {
            std::vector<std::string> row;
            for (int i = 1; i <= res->getMetaData()->getColumnCount(); i++) {
                row.push_back(res->getString(i)); // Agrega cada columna al vector.
            }
            results.push_back(row); // Agrega la fila completa al resultado final.
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error en SELECT: " << e.what() << std::endl;
    }
    return results; // Devuelve los resultados obtenidos.
}

// Método para ejecutar una consulta que no devuelva resultados (`INSERT`, `UPDATE`, etc.).
// Devuelve el número de filas afectadas o `-1` si hubo un error.
int DBContext::execute(const std::string& query) {
    try {
        std::unique_ptr<sql::Statement> stmt(connection->createStatement()); // Crea un statement.
        return stmt->executeUpdate(query); // Ejecuta la consulta.
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error en la ejecución de consulta: " << e.what() << std::endl;
        return -1; // Indica que hubo un error.
    }
}

// Método para eliminar filas de una tabla específica según una condición.
// Construye la consulta `DELETE` y utiliza el método `execute` para ejecutarla.
// Devuelve el número de filas afectadas o `-1` si hubo un error.
int DBContext::deleteRow(const std::string& table, const std::string& condition) {
    try {
        std::string query = "DELETE FROM " + table + " WHERE " + condition; // Construye la consulta.
        return execute(query); // Ejecuta la consulta usando el método `execute`.
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error al ejecutar DELETE: " << e.what() << std::endl;
        return -1; // Indica que hubo un error.
    }
}
