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
    //ajvnjanvlnad
    void LoadPiezas()
    {
        try
        {
            // Crear conexión MySQL
            sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
            std::unique_ptr<sql::Connection> con(driver->connect(
                "tcp://database-minipim.cdwgeayaeh1v.eu-central-1.rds.amazonaws.com:3306",
                "grupo07",
                "FjLWM6DNk6TJDzfV"
            ));
            con->setSchema("grupo07DB");

            if (con->isValid())
            {
                // Ejecutar consulta
                std::unique_ptr<sql::Statement> stmt(con->createStatement());
                std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT ID, NOMBRE, FABRICANTE, ID_TIPO FROM tPiezas"));

                // Limpiar y cargar datos al DataGridView
                testDataGridView->Rows->Clear();
                while (res->next())
                {
                    cli::array<String^>^ row = gcnew cli::array<String^>(4);
                    row[0] = res->isNull("ID") ? "" : gcnew String(res->getString("ID").c_str());
                    row[1] = res->isNull("NOMBRE") ? "" : gcnew String(res->getString("NOMBRE").c_str());
                    row[2] = res->isNull("FABRICANTE") ? "" : gcnew String(res->getString("FABRICANTE").c_str());
                    row[3] = res->isNull("ID_TIPO") ? "" : gcnew String(res->getString("ID_TIPO").c_str());
                    testDataGridView->Rows->Add(row);
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

// Punto de entrada principal de la aplicación
[STAThreadAttribute]
int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Test()); // Lanza el formulario principal "Test"
    return 0;
}
