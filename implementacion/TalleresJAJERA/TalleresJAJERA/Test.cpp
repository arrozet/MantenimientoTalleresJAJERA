#include "Test.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <iostream>
#include <string>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace sql;

namespace TalleresJAJERA {

    void Test::LoadPiezas()
    {
        try {
            // Crear el driver y la conexión
            sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
            Connection* con = driver->connect(
                "tcp://database-minipim.cdwgeayaeh1v.eu-central-1.rds.amazonaws.com:3306?auth_plugin=mysql_native_password",
                "grupo07",
                "FjLWM6DNk6TJDzfV"
            );

            // Seleccionar el esquema de la base de datos
            con->setSchema("grupo07DB");

            // Crear el objeto Statement
            Statement* stmt = con->createStatement();

            // Consulta SQL para seleccionar datos de la tabla tPiezas
            ResultSet* res = stmt->executeQuery("SELECT ID, NOMBRE, FABRICANTE, ID_TIPO FROM tPiezas");

            // Configurar columnas del DataGridView
            testDataGridView->ColumnCount = 4;
            testDataGridView->Columns[0]->Name = "ID";
            testDataGridView->Columns[1]->Name = "Nombre";
            testDataGridView->Columns[2]->Name = "Fabricante";
            testDataGridView->Columns[3]->Name = "ID_Tipo";

            // Agregar filas al DataGridView
            while (res->next()) {
                cli::array<String^>^ row = gcnew cli::array<String^>(4);
                row[0] = gcnew String(res->getString("ID").c_str());
                row[1] = gcnew String(res->getString("NOMBRE").c_str());
                row[2] = gcnew String(res->getString("FABRICANTE").c_str());
                row[3] = gcnew String(res->getString("ID_TIPO").c_str());
                testDataGridView->Rows->Add(row);
            }

            // Liberar recursos
            delete res;
            delete stmt;
            delete con;

        }
        catch (SQLException& e) {
            MessageBox::Show("SQL Error: " + gcnew String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (exception& e) {
            MessageBox::Show("Error general: " + gcnew String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    /*
    // Constructor del formulario
    Test::Test(void)
    {
        InitializeComponent();
        // Llenar el DataGridView cuando se carga el formulario
        LoadPiezas();
    }
    */
}
