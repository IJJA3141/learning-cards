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

void ResizeControlers(Control^ control, System::Drawing::Rectangle c, int newMainPageWidth)
{
    float r = (static_cast<float>(newMainPageWidth) / QzCPP::MainPage::MainWindowWidth);

    int newP = (c.X * r);
    int newS = (c.Width * r);

    control->Location = System::Drawing::Point(newP, control->Top);
    control->Width = newS;
}

System::Void QzCPP::MainPage::ResizeAll()
{
    this->Menu->Size = this->Size;
    //this->Learn->Size = this->Size;

    ResizeControlers(this->startCard,startCardButton,this->Width);
    ResizeControlers(this->startLearn, startLearnButton, this->Width);
    ResizeControlers(this->startWrite, startWriteButton, this->Width);
    ResizeControlers(this->StartPlusTard, startPlusTardButton, this->Width);
    ResizeControlers(this->backgroundInputZone, backgroundInputZonePanel, this->Width);
    ResizeControlers(this->bannerLightGrey, bannerLightGreyPanel, this->Width);
    ResizeControlers(this->panelTextBox, panelTextBoxPanel, this->Width);
    ResizeControlers(this->rightTextBox, rightTextBoxTextBox, this->Width);
    ResizeControlers(this->leftTextBox, leftTextBoxTextBox, this->Width);
    ResizeControlers(this->panelRedDarck, panelRedDarckPanel, this->Width);
}


[STAThread]

void main() {
    System::Windows::Forms::Application::EnableVisualStyles();
    QzCPP::MainPage form;
    Application::Run(% form);
}