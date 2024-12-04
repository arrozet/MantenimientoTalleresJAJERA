#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <iostream>

using namespace std;

int main()
{
    try {
        // Crear el driver y la conexión
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        // Inicializar el driver y conectar a la base de datos
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(
            "tcp://database-minipim.cdwgeayaeh1v.eu-central-1.rds.amazonaws.com:3306?auth_plugin=mysql_native_password",
            "grupo07",
            "FjLWM6DNk6TJDzfV"
        );


        // Seleccionar el esquema de la base de datos
        con->setSchema("grupo07DB"); // Nombre de la base de datos

        // Crear el objeto Statement
        sql::Statement* stmt;
        stmt = con->createStatement();

        // Consulta SQL para seleccionar datos de la tabla tPiezas
        string selectDataSQL = "SELECT ID, NOMBRE, FABRICANTE, ID_TIPO FROM tPiezas";

        // Ejecutar la consulta y almacenar los resultados
        sql::ResultSet* res = stmt->executeQuery(selectDataSQL);

        // Mostrar los datos obtenidos
        while (res->next()) {
            cout << "ID: " << res->getInt("ID")
                << ", Nombre: " << res->getString("NOMBRE")
                << ", Fabricante: " << res->getString("FABRICANTE")
                << ", ID_Tipo: " << res->getInt("ID_TIPO")
                << endl;
        }

        // Liberar recursos
        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        // Manejar errores de SQL
        cerr << "SQL Error: " << e.what() << endl;
        cerr << "Código de error: " << e.getErrorCode() << endl;
        cerr << "Estado SQL: " << e.getSQLState() << endl;
    }
    catch (exception& e) {
        // Manejar otros errores
        cerr << "Error general: " << e.what() << endl;
    }

    return 0;
}
