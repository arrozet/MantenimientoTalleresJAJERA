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
            // Crear conexión MySQL con las credenciales de AWS
            sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
            std::unique_ptr<sql::Connection> con(driver->connect(
                "tcp://database-minipim.cdwgeayaeh1v.eu-central-1.rds.amazonaws.com:3306", // Host y puerto
                "grupo07",  // Usuario
                "FjLWM6DNk6TJDzfV" // Contraseña
            ));
            con->setSchema("grupo07DB"); // Base de datos

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

                    // Manejar valores NULL correctamente
                    row[0] = res->isNull("ID") ? "NULL" : gcnew String(res->getString("ID").c_str());
                    row[1] = res->isNull("NOMBRE") ? "NULL" : gcnew String(res->getString("NOMBRE").c_str());
                    row[2] = res->isNull("FABRICANTE") ? "NULL" : gcnew String(res->getString("FABRICANTE").c_str());
                    row[3] = res->isNull("ID_TIPO") ? "NULL" : gcnew String(res->getString("ID_TIPO").c_str());

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
            String^ errorMessage = "Error al cargar datos:\n" +
                "Mensaje: " + gcnew String(e.what()) + "\n" +
                "SQLState: " + gcnew String(e.getSQLState().c_str()) + "\n" +
                "Código de error: " + e.getErrorCode();
            MessageBox::Show(errorMessage, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
