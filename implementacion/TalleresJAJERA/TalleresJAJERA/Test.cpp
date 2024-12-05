#include "Test.h"
#include "DBContext.h"
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
            // Crear una instancia de DBContext
            DBContext db("database-minipim.cdwgeayaeh1v.eu-central-1.rds.amazonaws.com:3306?auth_plugin=mysql_native_password",
                "grupo07",
                "FjLWM6DNk6TJDzfV",
                "grupo07DB");

            if (db.connect()) {
                // Consulta SQL para seleccionar datos de la tabla tPiezas
                auto res = db.select("SELECT ID, NOMBRE, FABRICANTE, ID_TIPO FROM tPiezas");

                // Configurar columnas del DataGridView
                testDataGridView->ColumnCount = 4;
                testDataGridView->Columns[0]->Name = "ID";
                testDataGridView->Columns[1]->Name = "Nombre";
                testDataGridView->Columns[2]->Name = "Fabricante";
                testDataGridView->Columns[3]->Name = "ID_Tipo";

                // Agregar filas al DataGridView
                for (const auto& row : res) {
                    cli::array<String^>^ managedRow = gcnew cli::array<String^>(4);
                    managedRow[0] = gcnew String(row[0].c_str());
                    managedRow[1] = gcnew String(row[1].c_str());
                    managedRow[2] = gcnew String(row[2].c_str());
                    managedRow[3] = gcnew String(row[3].c_str());
                    testDataGridView->Rows->Add(managedRow);
                }

                // Consulta SQL para llenar el ListBox con nombres de tipos de piezas
                auto res2 = db.select("SELECT NOMBRE FROM tTipoPieza");

                for (const auto& row : res2) {
                    String^ item = gcnew String(row[0].c_str());
                    lMaterias->Items->Add(item);
                }

               
            }
            else {
                MessageBox::Show("Error al conectar a la base de datos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        catch (std::exception& e) {
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
