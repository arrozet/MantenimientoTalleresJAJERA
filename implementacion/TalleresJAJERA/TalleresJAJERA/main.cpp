#include "Test.h"
#include "Login.h"
#include <locale.h>
#include <windows.h>
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

// No es necesario definir `main` en aplicaciones de Windows Forms
[STAThreadAttribute]
void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Ejecutar el formulario principal
    TalleresJAJERA::Login LoginForm;
    Application::Run(% LoginForm);
}

