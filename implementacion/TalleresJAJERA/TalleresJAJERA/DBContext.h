#pragma once
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <vector>
#include <string>

// Habilitamos el uso del namespace std
using namespace std;

class DBContext {
private:
    sql::Driver* driver;                        // Driver para MySQL.
    unique_ptr<sql::Connection> connection;     // Conexi�n a la base de datos.

public:
    // Constructor y destructor.
    DBContext();
    ~DBContext();

    // M�todos de conexi�n y operaciones sobre la base de datos.
    bool connect();
    bool close();
    vector<vector<string>> select(const string& query);
    int execute(const string& query);
    int deleteRow(const string& table, const string& condition);
    // Funci�n est�tica para convertir un std::string a System::String con codificaci�n UTF-8
    static System::String^ ConvertToUTF8(const std::string& input);
    // Funci�n est�tica para convertir un System::String (UTF-8) a std::string
    static std::string ConvertFromUTF8(System::String^ input);

    // Credenciales est�ticas para la base de datos.
    static string Host;
    static string User;
    static string Password;
    static string Database;
};
