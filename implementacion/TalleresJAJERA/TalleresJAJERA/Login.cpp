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


    bool Login::autenticar(const std::string& nombre, const std::string& password) {
        try {
            // Buscar al usuario en la base de datos
            Usuario usuario = Usuario(nombre);
            if (usuario.getPassword() == password) {
                return true; // Contrase�a correcta
            }
            return false; // Contrase�a incorrecta
        }
        catch (const std::exception& e) {
            // Si no se encuentra el usuario
            MessageBox::Show("Error de autenticaci�n: " + gcnew String(e.what()));
            return false;
        }
    }
    
    void Login::bOk_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Obtener los valores de las TextBox
            std::string nombreUsuario = msclr::interop::marshal_as<std::string>(tUsuario->Text);
            std::string contrasena = msclr::interop::marshal_as<std::string>(tPassword->Text);

            // Verificar si los campos est�n vac�os
            if (nombreUsuario.empty() || contrasena.empty()) {
                MessageBox::Show("Ambos campos son obligatorios.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Intentar obtener el usuario de la base de datos

            // Verificar si la contrase�a es correcta
            if (autenticar(nombreUsuario,contrasena)) {
                // Si el usuario es autenticado correctamente, puedes continuar con el siguiente paso (ej. redirigir a otra ventana)
                MessageBox::Show("Login exitoso", "Bienvenido", MessageBoxButtons::OK, MessageBoxIcon::Information);

                // Llamar al siguiente paso del login, como abrir la siguiente ventana
                this->Hide();
                Test^ testForm = gcnew Test();
                testForm->ShowDialog();
            }
        }
        catch (const std::exception& e) {
            // Si el usuario no existe, capturamos la excepci�n y mostramos un mensaje de error
            MessageBox::Show("El usuario no existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    
}