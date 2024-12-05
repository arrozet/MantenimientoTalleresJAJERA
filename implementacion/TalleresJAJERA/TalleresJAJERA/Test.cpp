#include "Test.h"
#include "DBContext.h"
#include "Pieza.h"
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
            // Obtener la lista de piezas usando la clase Pieza
            auto piezas = Pieza::ListarTodas();

            // Configurar columnas del DataGridView
            testDataGridView->ColumnCount = 4;
            testDataGridView->Columns[0]->Name = "ID";
            testDataGridView->Columns[1]->Name = "Nombre";
            testDataGridView->Columns[2]->Name = "Fabricante";
            testDataGridView->Columns[3]->Name = "ID_Tipo";

            // Agregar filas al DataGridView desde la lista de piezas
            for (const auto& pieza : piezas) {
                cli::array<String^>^ managedRow = gcnew cli::array<String^>(4);
                managedRow[0] = gcnew String(std::to_string(pieza.getId()).c_str());
                managedRow[1] = gcnew String(pieza.toString().c_str());
                managedRow[2] = gcnew String(pieza.getFabricante().c_str());
                managedRow[3] = gcnew String(pieza.getIdTipo().c_str());
                testDataGridView->Rows->Add(managedRow);
            }

            // Obtener nombres de tipos de piezas y llenar el ListBox
            /*auto tipos = Pieza::ListarTodas();
            for (const auto& tipo : tipos) {
                lMaterias->Items->Add(gcnew String(tipo.c_str()));
            }*/
        }
        catch (std::exception& e) {
            MessageBox::Show("Error general: " + gcnew String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    Void Test::bLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Vaciar el contenido de la listBox 
            lMaterias->SelectedItem = nullptr;

            // Deseleccionar cualquier objeto del DataGridView 
            testDataGridView->ClearSelection();

            // Eliminar el texto de los textBox 
            tNombre->Text = "";
            tFabricante->Text = "";
        }
        catch (System::Exception^ ex) {
            MessageBox::Show("Ocurrió un error en Limpiar: " + ex->Message);
        }

    }

    Void Test:: testDataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        try {
            tNombre->Text = testDataGridView->SelectedRows[0]->Cells["Nombre"]->Value->ToString();
            tFabricante->Text = testDataGridView->SelectedRows[0]->Cells["Fabricante"]->Value->ToString();
            //AQUI HAY QUE PONER QUE SE SELECCIONE
            // DE LA LISTBOX EL NOMBRE DEL TIPOPRODUCTO SELECCIONADO (IDPRODUCTO)


        }
        catch (System::Exception^ ex) {
            MessageBox::Show("Ocurrió un error al hacer click en el dataGridView: " + ex->Message);
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
