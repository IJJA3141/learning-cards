#include "MainPage.h"

System::Void QzCPP::MainPage::MainPageResize(System::Object^ sender, System::EventArgs^ e)
{

}

[STAThread]

void main() {
    System::Windows::Forms::Application::EnableVisualStyles();
    QzCPP::MainPage form;
}