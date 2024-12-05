#pragma once
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <vector>
#include <string>

class DBContext {
private:
    sql::Driver* driver;                        // Driver para MySQL.
    std::unique_ptr<sql::Connection> connection; // Conexión a la base de datos.

public:
    // Constructor y destructor.
    DBContext();
    ~DBContext();

    // Métodos de conexión y operaciones sobre la base de datos.
    bool connect();
    bool close();
    std::vector<std::vector<std::string>> select(const std::string& query);
    int execute(const std::string& query);
    int deleteRow(const std::string& table, const std::string& condition);

    // Credenciales estáticas para la base de datos.
    static std::string Host;
    static std::string User;
    static std::string Password;
    static std::string Database;
};
