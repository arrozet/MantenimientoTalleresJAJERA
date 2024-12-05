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

            // Verificar si la contrase�a es correcta
            if (usuario.getPassword() == password) {
                return usuario.getRolName();  // Devolver el rol si la contrase�a es correcta
            }
            else {
                return "error";  // Contrase�a incorrecta, retornar una cadena vac�a
            }
        }
        catch (const std::exception& e) {
            // Si no se encuentra el usuario o hay un error
            MessageBox::Show("Error de autenticaci�n: " + gcnew String(e.what()));
            return ""; // Error en la autenticaci�n, retornar cadena vac�a
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
            string rol = autenticar(nombreUsuario, contrasena);
            if (rol != "error") {
                // Si el usuario es autenticado correctamente, puedes continuar con el siguiente paso (ej. redirigir a otra ventana)
                MessageBox::Show("Login exitoso", "Bienvenido", MessageBoxButtons::OK, MessageBoxIcon::Information);

                // Llamar al siguiente paso del login, como abrir la siguiente ventana
                this->Hide();
                Test^ testForm = gcnew Test(rol);
                testForm->ShowDialog();
            }
        }
        catch (const std::exception& e) {
            // Si el usuario no existe, capturamos la excepci�n y mostramos un mensaje de error
            MessageBox::Show("El usuario no existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    
}