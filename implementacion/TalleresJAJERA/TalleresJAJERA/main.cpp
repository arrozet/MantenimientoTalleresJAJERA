#include "Test.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    // Habilitar estilos visuales para los controles
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Ejecutar el formulario principal
    TalleresJAJERA::Test testForm;
    Application::Run(% testForm);

    return 0;
}
