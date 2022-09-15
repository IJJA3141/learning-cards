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

void ResizeControlersAll(Control^ control, System::Drawing::Rectangle c, int newMainPageWidth, int newMainPageHeight)
{
    float horizontalRatio = (static_cast<float>(newMainPageWidth) / QzCPP::MainPage::MainWindowWidth);
    float verticalRatio = (static_cast<float>(newMainPageHeight) / QzCPP::MainPage::MainWindowHeight);

    int newX = (c.X * horizontalRatio);
    int newWidth = (c.Width * horizontalRatio);

    int newY = (c.Y * verticalRatio);
    int newHeight = (c.Height * horizontalRatio);

    control->Location = System::Drawing::Point(newX, newY);
    control->Size = System::Drawing::Size(newWidth, newHeight);
}

void ResizeControlersPlus(Control^ control, System::Drawing::Rectangle c, int newMainPageWidth, int newMainPageHeight)
{
    float horizontalRatio = (static_cast<float>(newMainPageWidth) / QzCPP::MainPage::MainWindowWidth);
    float verticalRatio = (static_cast<float>(newMainPageHeight) / QzCPP::MainPage::MainWindowHeight);

    int newX = (c.X * horizontalRatio);
    int newWidth = (c.Width * horizontalRatio);

    int newHeight = (c.Height * horizontalRatio);

    control->Location = System::Drawing::Point(newX, control->Top);
    control->Size = System::Drawing::Size(newWidth, newHeight);
}

System::Void QzCPP::MainPage::ResizeAll()
{
    this->Menu->Size = System::Drawing::Size(this->Width, this->Height);
    this->backgroundMask->Size = System::Drawing::Size(this->Width, this->Height - QzCPP::MainPage::MainWindowHeight * 35 / 100);
    this->scrollBar->Height = this->Height;
    
    this->backgroundInputZone->Width = this->Width;
    //this->Learn->Size = this->Size;

    ResizeControlers(this->startCard,startCardButton,this->Width);
    ResizeControlers(this->startLearn, startLearnButton, this->Width);
    ResizeControlers(this->startWrite, startWriteButton, this->Width);
    ResizeControlers(this->StartPlusTard, startPlusTardButton, this->Width);

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