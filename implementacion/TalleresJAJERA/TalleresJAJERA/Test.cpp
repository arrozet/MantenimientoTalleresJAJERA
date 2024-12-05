#include "Test.h"
#include "DBContext.h"
#include "Pieza.h"
#include "TipoPieza.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <iostream>
#include <string>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace sql;
using namespace msclr::interop;

namespace TalleresJAJERA {

    void Test::LoadPiezas()
    {
        try {
            // Limpiar los ítems existentes en el ListBox
            lMaterias->Items->Clear();

            // Obtener todos los tipos de piezas
            auto tipoPiezas = TipoPieza::ListarTodos();

            // Llenar el ListBox con los nombres
            for (const auto& tipo : tipoPiezas) {
                lMaterias->Items->Add(gcnew System::String(tipo.getNombre().c_str()));
            }

            // Configurar columnas del DataGridView
            testDataGridView->ColumnCount = 4;
            testDataGridView->Columns[0]->Name = "ID";
            testDataGridView->Columns[1]->Name = "Nombre";
            testDataGridView->Columns[2]->Name = "Fabricante";
            testDataGridView->Columns[3]->Name = "ID_Tipo";

            
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

    void Test::lMaterias_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        // Obtener la lista de piezas usando la clase Pieza
        auto tipoSeleccionado = marshal_as<string>(lMaterias->SelectedItem->ToString());
        cout << tipoSeleccionado << endl;
        auto piezas = Pieza::ListarPorTipo(tipoSeleccionado);

        // Limpiar las filas existentes en el DataGridView
        testDataGridView->Rows->Clear();

        // Agregar filas al DataGridView desde la lista de piezas
        for (const auto& pieza : piezas) {
            cli::array<String^>^ managedRow = gcnew cli::array<String^>(4);
            managedRow[0] = gcnew String(std::to_string(pieza.getId()).c_str());
            managedRow[1] = gcnew String(pieza.toString().c_str());
            managedRow[2] = gcnew String(pieza.getFabricante().c_str());
            managedRow[3] = gcnew String(pieza.getIdTipo().c_str());
            testDataGridView->Rows->Add(managedRow);
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
