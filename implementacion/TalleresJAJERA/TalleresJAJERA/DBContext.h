#pragma once
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <vector>
#include <string>

class DBContext {
private:
    sql::Driver* driver;
    std::unique_ptr<sql::Connection> connection;
    std::string host;
    std::string user;
    std::string password;
    std::string database;

public:
    DBContext(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
    ~DBContext();

    bool connect();
    std::vector<std::vector<std::string>> select(const std::string& query);
    int execute(const std::string& query);
    int deleteRow(const std::string& table, const std::string& condition);
};
