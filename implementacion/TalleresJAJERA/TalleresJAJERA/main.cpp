#include "Test.h"
#include "Login.h"
#include <locale.h>
#include <windows.h>
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(String^ args)
{

    // Habilitar estilos visuales para los controles
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Ejecutar el formulario principal
    TalleresJAJERA::Login LoginForm;
    Application::Run(% LoginForm);

    return 0;
}
