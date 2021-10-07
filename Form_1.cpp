#include "Form_1.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
    FreeConsole();
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MouseController::Form_1 form;
    Application::Run(% form);
}