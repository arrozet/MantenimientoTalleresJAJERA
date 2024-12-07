#include "Login.h"
#include "DBContext.h"
#include "Pieza.h"
#include "TipoPieza.h"
#include "Test.h"  
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


    std::string Login::autenticar(const std::string& nombre, const std::string& password) {
        try {
            // Buscar al usuario en la base de datos
            Usuario usuario = Usuario(nombre);

            // Verificar si la contraseña es correcta
            
            if (usuario.getNombre() != nombre) {
                return "error";
            }
            if (usuario.getPassword() == password) {
                return usuario.getRolName();  // Devolver el rol si la contraseña es correcta
            }
            else {
                return "error";  // Contraseña incorrecta, retornar una cadena vacía
            }
        }
        catch (const std::exception& e) {
            // Si no se encuentra el usuario o hay un error
            MessageBox::Show("Error de autenticación: " + gcnew String(e.what()),"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return ""; // Error en la autenticación, retornar cadena vacía
        }
    }
    
    void Login::bOk_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Obtener los valores de las TextBox
            std::string nombreUsuario = msclr::interop::marshal_as<std::string>(tUsuario->Text);
            std::string contrasena = msclr::interop::marshal_as<std::string>(tPassword->Text);

            // Verificar si los campos están vacíos
            if (nombreUsuario.empty() || contrasena.empty()) {
                MessageBox::Show("Ambos campos son obligatorios.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Intentar obtener el usuario de la base de datos

            // Verificar si la contraseña es correcta
            string rol = autenticar(nombreUsuario, contrasena);
            if (rol != "error" && rol != "") {
                // Si el usuario es autenticado correctamente, puedes continuar con el siguiente paso (ej. redirigir a otra ventana)
                MessageBox::Show("Login exitoso", "Bienvenido", MessageBoxButtons::OK, MessageBoxIcon::Information);

                // Llamar al siguiente paso del login, como abrir la siguiente ventana
                this->Hide();
                Test^ testForm = gcnew Test(rol);
                testForm->ShowDialog();
                this->Close();
            }
            else {
                MessageBox::Show("Alguno de los campos introducidos no es correcto", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
        }
        catch (const std::exception& e) {
            // Si el usuario no existe, capturamos la excepción y mostramos un mensaje de error
            MessageBox::Show("El usuario no existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    void Login::Login_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
        if (e->KeyCode == Keys::Enter) {
            // Simula un clic en el botón OK
            bOk_Click(sender, e);
            e->SuppressKeyPress = true; // Evitar el sonido de error del sistema
        }
    }

    void Login::bCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    
}