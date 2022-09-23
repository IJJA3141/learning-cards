#include "MainPage.h"

[System::STAThread]

void main() {
    System::Windows::Forms::Application::EnableVisualStyles();
    QzCPP::MainPage form;
    System::Windows::Forms::Application::Run(% form);
}