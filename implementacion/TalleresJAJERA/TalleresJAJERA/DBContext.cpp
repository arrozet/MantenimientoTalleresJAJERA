#include "DBContext.h"
#include <iostream>

// Constructor: Inicializa los atributos con los parámetros proporcionados.
// Establece los valores necesarios para conectar a la base de datos.
DBContext::DBContext(const std::string& host, const std::string& user, const std::string& password, const std::string& database)
    : host(host), user(user), password(password), database(database), driver(nullptr) {
}

// Destructor: Se asegura de cerrar la conexión si está abierta antes de destruir la instancia.
DBContext::~DBContext() {
    if (connection) {
        connection->close();
    }
}

// Método para establecer una conexión con la base de datos.
// Usa el driver de MySQL para conectarse al host especificado.
// Devuelve `true` si la conexión fue exitosa, de lo contrario `false`.
bool DBContext::connect() {
    try {
        driver = get_driver_instance(); // Obtiene la instancia del driver de MySQL.
        connection = std::unique_ptr<sql::Connection>(driver->connect("tcp://" + host, user, password));
        connection->setSchema(database); // Establece el esquema (base de datos).
        std::cout << "Conexión establecida con Éxito.\n";
        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error de conexión: " << e.what() << std::endl;
        return false;
    }
}

// Método para cerrar la conexión con la base de datos.
// Devuelve `true` si la operación fue exitosa, de lo contrario `false`.
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
        //close(); // Comentado, ya que podría ser un comportamiento opcional.
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
