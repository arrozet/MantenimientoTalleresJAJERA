#include "DBContext.h"
#include <iostream>


DBContext::DBContext(const std::string& host, const std::string& user, const std::string& password, const std::string& database)
    : host(host), user(user), password(password), database(database), driver(nullptr) {}

DBContext::~DBContext() {
    if (connection) {
        connection->close();
    }
}

bool DBContext::connect() {
    try {
        driver = get_driver_instance();
        connection = std::unique_ptr<sql::Connection>(driver->connect("tcp://" + host, user, password));
        connection->setSchema(database);
        std::cout << "Conexión establecida con éxito.\n";
        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error de conexión: " << e.what() << std::endl;
        return false;
    }
}

std::vector<std::vector<std::string>> DBContext::select(const std::string& query) {
    std::vector<std::vector<std::string>> results;
    try {
        std::unique_ptr<sql::Statement> stmt(connection->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(query));

        while (res->next()) {
            std::vector<std::string> row;
            for (int i = 1; i <= res->getMetaData()->getColumnCount(); i++) {
                row.push_back(res->getString(i));
            }
            results.push_back(row);
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error en SELECT: " << e.what() << std::endl;
    }
    return results;
}

int DBContext::execute(const std::string& query) {
    try {
        std::unique_ptr<sql::Statement> stmt(connection->createStatement());
        return stmt->executeUpdate(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error en la ejecución de consulta: " << e.what() << std::endl;
        return -1;
    }
}

int DBContext::deleteRow(const std::string& table, const std::string& condition) {
    try {
        std::string query = "DELETE FROM " + table + " WHERE " + condition;
        return execute(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error al ejecutar DELETE: " << e.what() << std::endl;
        return -1;
    }
}
