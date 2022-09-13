#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
#include "MainPage.h"
#include <fstream>
#include <codecvt>
#include <codecvt>
#include <cassert>
#include <locale>   
#include <string>
#include <vector>

#include <algorithm>
#include <random>

using namespace System::Windows::Forms;
using namespace System;
using namespace std;

void ResizeControlers(Control^ control, int initialControlWidth, int newMainPageWidth)
{
    float r = (static_cast<float>(newMainPageWidth) / QzCPP::MainPage::MainWindowWidth);

    int newS = (initialControlWidth * r);

    control->Location = System::Drawing::Point(newS, control->Top);
    control->Width = newS;
}

System::Void QzCPP::MainPage::ResizeAll()
{
    ResizeControlers(this->Menu, 1000, this->Width);
}


[STAThread]

void main() {
    System::Windows::Forms::Application::EnableVisualStyles();
    QzCPP::MainPage form;
    Application::Run(% form);
}