#include "Test.h"
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/resultset.h>

using namespace System;
using namespace System::Windows::Forms;

void Test::LoadPiezas()
{
    try
    {
        // Crear conexión MySQL
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "usuario", "contraseña"));
        con->setSchema("nombre_base_datos");

        // Ejecutar consulta
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT ID, NOMBRE, FABRICANTE, ID_TIPO FROM tPiezas"));

        // Configurar DataGridView
        dataGridView1->Rows->Clear();
        dataGridView1->ColumnCount = 4;
        dataGridView1->Columns[0]->Name = "ID";
        dataGridView1->Columns[1]->Name = "Nombre";
        dataGridView1->Columns[2]->Name = "Fabricante";
        dataGridView1->Columns[3]->Name = "ID Tipo";

        // Agregar datos al DataGridView
        while (res->next())
        {
            dataGridView1->Rows->Add(gcnew cli::array<String^>{
                gcnew String(res->getString("ID").c_str()),
                    gcnew String(res->getString("NOMBRE").c_str()),
                    gcnew String(res->getString("FABRICANTE").c_str()),
                    gcnew String(res->getString("ID_TIPO").c_str())
            });
        }
    }
    catch (sql::SQLException& e)
    {
        MessageBox::Show("Error al cargar datos: " + gcnew String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}


