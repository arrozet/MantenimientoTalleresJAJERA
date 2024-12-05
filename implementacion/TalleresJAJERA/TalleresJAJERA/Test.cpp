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
                // Convertir el nombre usando la función estática ConvertToUTF8
                auto managedString = DBContext::ConvertToUTF8(tipo.getNombre());
                lMaterias->Items->Add(managedString);
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

    void Test::refreshDataGridForSelectedType(const std::string& tipoSeleccionado) {
        try {
            // Obtener la lista de piezas usando la clase Pieza para el tipo seleccionado
            auto piezas = Pieza::ListarPorTipo(tipoSeleccionado);

            // Limpiar las filas existentes en el DataGridView
            testDataGridView->Rows->Clear();

            // Agregar filas al DataGridView desde la lista de piezas
            for (const auto& pieza : piezas) {
                cli::array<String^>^ managedRow = gcnew cli::array<String^>(4);
                // Convertir a System::String usando ConvertToUTF8 para cada campo
                managedRow[0] = gcnew String(std::to_string(pieza.getId()).c_str());

                // Convertir a System::String para campos con caracteres especiales (tildes)
                managedRow[1] = DBContext::ConvertToUTF8(pieza.toString());  // Nombre de la pieza
                managedRow[2] = DBContext::ConvertToUTF8(pieza.getFabricante());  // Fabricante
                managedRow[3] = DBContext::ConvertToUTF8(pieza.getIdTipo());  // Tipo de pieza
                testDataGridView->Rows->Add(managedRow);
            }
        }
        catch (const std::exception& ex) {
            // Manejo de errores en caso de que ocurra un problema
            MessageBox::Show("Error al cargar las piezas: " + gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }


    Void Test::bLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Vaciar el contenido de la listBox 
            lMaterias->ClearSelected();

            // Deseleccionar cualquier objeto del DataGridView 
            testDataGridView->Rows->Clear();

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
        if (lMaterias->SelectedIndex >= 0) {
            // Obtener la lista de piezas usando la clase Pieza
            auto tipoSeleccionado = DBContext::ConvertFromUTF8(lMaterias->SelectedItem->ToString());
            cout << tipoSeleccionado << endl;

            // Llamar al nuevo método para refrescar el DataGridView
            refreshDataGridForSelectedType(tipoSeleccionado);
        }
    }


    Void Test::bInsertar_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Obtener los valores de los TextBox
            String^ nombre = tNombre->Text;
            String^ fabricante = tFabricante->Text;

            // Verificar que los campos no estén vacíos
            if (String::IsNullOrEmpty(nombre) || String::IsNullOrEmpty(fabricante)) {
                MessageBox::Show("Por favor ingrese tanto el nombre como el fabricante.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Obtener el tipo seleccionado desde el ListBox (lMaterias debe contener nombres de tipos de tTipoPieza)
            String^ nombreTipo = lMaterias->SelectedItem != nullptr ? lMaterias->SelectedItem->ToString() : nullptr;

            // Verificar que el nombreTipo no sea nulo
            if (String::IsNullOrEmpty(nombreTipo)) {
                MessageBox::Show("Por favor seleccione un tipo de pieza.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Convertir los valores de los controles a std::string usando DBContext::ConvertFromUTF8
            std::string nombreStr = DBContext::ConvertFromUTF8(nombre);
            std::string fabricanteStr = DBContext::ConvertFromUTF8(fabricante);
            std::string nombreTipoStr = DBContext::ConvertFromUTF8(nombreTipo);

            // Buscar el ID_TIPO correspondiente al nombre del tipo
            DBContext db;
            auto res = db.select("SELECT ID_TIPO FROM tTipoPieza WHERE NOMBRE = '" + nombreTipoStr + "'");
            if (res.empty()) {
                MessageBox::Show("No se encontró el tipo de pieza seleccionado en la base de datos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            std::string idTipoStr = res[0][0]; // Obtener el ID_TIPO del resultado

            // Crear una nueva pieza usando el constructor
            Pieza nuevaPieza(nombreStr, fabricanteStr, idTipoStr);

            // Mostrar mensaje de éxito
            MessageBox::Show("Pieza insertada con éxito.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

            // Limpiar los campos de los TextBox
            tNombre->Text = "";
            tFabricante->Text = "";

            // Llamar al nuevo método para refrescar el DataGridView
            refreshDataGridForSelectedType(DBContext::ConvertFromUTF8(lMaterias->SelectedItem->ToString()));
        }
        catch (std::exception& ex) {
            // Mostrar cualquier error ocurrido durante el proceso
            MessageBox::Show("Ocurrió un error en la inserción: " + gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (System::Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

    }

    Void Test::bEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Verificar que haya una fila seleccionada en el DataGridView
            if (testDataGridView->SelectedRows->Count > 0) {
                // Obtener el ID de la pieza seleccionada (suponiendo que está en la primera columna)
                int selectedRowIndex = testDataGridView->SelectedRows[0]->Index;
                String^ idString = testDataGridView->Rows[selectedRowIndex]->Cells["ID"]->Value->ToString();

                // Convertir el ID de String^ a int
                int idPieza = System::Int32::Parse(idString);

                // Crear una pieza con el ID de la pieza seleccionada
                Pieza piezaAEliminar(idPieza);

                // Llamar al método borrar para eliminar la pieza de la base de datos
                piezaAEliminar.borrar();

                // Mostrar mensaje de éxito
                MessageBox::Show("Pieza eliminada con éxito.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

                // Recargar el DataGridView para reflejar la eliminación
                refreshDataGridForSelectedType(DBContext::ConvertFromUTF8(lMaterias->SelectedItem->ToString()));
            }
            else {
                MessageBox::Show("Por favor seleccione una pieza para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        catch (const std::exception& ex) {
            // Manejo de errores si ocurre una excepción
            MessageBox::Show("Error al eliminar la pieza: " + gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (System::Exception^ ex) {
            // Manejo de excepciones de .NET
            MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }


    Void Test::bActualizar_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Verificar que haya una fila seleccionada en el DataGridView
            if (testDataGridView->SelectedRows->Count > 0) {
                // Obtener el ID de la pieza seleccionada (suponiendo que está en la primera columna)
                int selectedRowIndex = testDataGridView->SelectedRows[0]->Index;
                String^ idString = testDataGridView->Rows[selectedRowIndex]->Cells["ID"]->Value->ToString();

                // Convertir el ID de String^ a int
                int idPieza = System::Int32::Parse(idString);

                // Obtener los nuevos valores de los TextBox
                String^ nuevoNombre = tNombre->Text;
                String^ nuevoFabricante = tFabricante->Text;
                String^ nuevoTipo = lMaterias->SelectedItem != nullptr ? lMaterias->SelectedItem->ToString() : nullptr;

                // Verificar que los campos no estén vacíos
                if (String::IsNullOrEmpty(nuevoNombre) || String::IsNullOrEmpty(nuevoFabricante) || String::IsNullOrEmpty(nuevoTipo)) {
                    MessageBox::Show("Por favor ingrese todos los campos para actualizar la pieza.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                // Convertir los valores de los controles a std::string usando ConvertFromUTF8
                std::string nombreStr = DBContext::ConvertFromUTF8(nuevoNombre);
                std::string fabricanteStr = DBContext::ConvertFromUTF8(nuevoFabricante);
                std::string tipoStr = DBContext::ConvertFromUTF8(nuevoTipo);

                // Crear un objeto Pieza con el ID de la pieza seleccionada
                Pieza piezaAActualizar(idPieza);

                // Actualizar los campos de la pieza
                piezaAActualizar.setNombre(nombreStr);
                piezaAActualizar.setFabricante(fabricanteStr);
                piezaAActualizar.setIdTipo(tipoStr);

                // Mostrar mensaje de éxito
                MessageBox::Show("Pieza actualizada con éxito.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

                // Limpiar los campos de los TextBox
                tNombre->Text = "";
                tFabricante->Text = "";

                // Recargar el DataGridView para reflejar la actualización
                refreshDataGridForSelectedType(DBContext::ConvertFromUTF8(lMaterias->SelectedItem->ToString()));
            }
            else {
                MessageBox::Show("Por favor seleccione una pieza para actualizar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        catch (System::Exception^ ex) {
            // Manejo de excepciones de .NET
            MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

    }

}
