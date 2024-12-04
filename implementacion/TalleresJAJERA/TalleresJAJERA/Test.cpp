#pragma once
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/resultset.h>
#include <memory>
#include <string>
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

public ref class Test : public Form
{
private:
    DataGridView^ testDataGridView;

public:
    Test()
    {
        // Inicialización de componentes y DataGridView
        InitializeComponent();
    }

    void InitializeComponent()
    {
        this->testDataGridView = gcnew DataGridView();
        this->testDataGridView->Dock = DockStyle::Fill;
        this->Controls->Add(this->testDataGridView);

        // Configurar columnas solo una vez
        testDataGridView->ColumnCount = 4;
        testDataGridView->Columns[0]->Name = "ID";
        testDataGridView->Columns[1]->Name = "Nombre";
        testDataGridView->Columns[2]->Name = "Fabricante";
        testDataGridView->Columns[3]->Name = "ID Tipo";

        this->Load += gcnew EventHandler(this, &Test::Test_Load);
    }

    void Test_Load(Object^ sender, EventArgs^ e)
    {
        LoadPiezas();
    }

    void LoadPiezas()
    {
        try
        {
            // Crear conexión MySQL
            sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
            std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "usuario", "contraseña"));
            con->setSchema("nombre_base_datos");

            if (con->isValid())
            {
                // Ejecutar consulta
                std::unique_ptr<sql::Statement> stmt(con->createStatement());
                std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT ID, NOMBRE, FABRICANTE, ID_TIPO FROM tPiezas"));

                // Limpiar y cargar datos al DataGridView
                testDataGridView->Rows->Clear();
                while (res->next())
                {
                    testDataGridView->Rows->Add(gcnew cli::array<String^>{
                        gcnew String(res->getString("ID").c_str()),
                            gcnew String(res->getString("NOMBRE").c_str()),
                            gcnew String(res->getString("FABRICANTE").c_str()),
                            gcnew String(res->getString("ID_TIPO").c_str())
                    });
                }
            }
            else
            {
                MessageBox::Show("La conexión a la base de datos no es válida.", "Error de conexión", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        catch (sql::SQLException& e)
        {
            MessageBox::Show("Error al cargar datos: " + gcnew String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (std::exception& e)
        {
            MessageBox::Show("Error general: " + gcnew String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
};

