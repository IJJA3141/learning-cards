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

int handleSize(int windowHeight, int backgroundHeight, int backgroundTop)
{
    int offPart = backgroundHeight - (windowHeight - backgroundTop);
    int all = backgroundTop + offPart;
    int onPart = all - offPart;

    int handleHeight = windowHeight * onPart / all;
    return handleHeight;
}

System::Void QzCPP::MainPage::ResizeAll()
{ 
    // Special Things
    int windWidh = this->Width - 16;
    int windHeight = this->Height - 39;

    int menuHeight = this->Menu->Height;
    int menuTop = -this->Menu->Top;

    int backHeight = this->backgroundInputZone->Height;
    int backTop = this->backgroundInputZone->Top;

    // Menu
    this->Menu->Width = windWidh;

    if (this->Menu->Top < 0)
    {
        if (0 < menuHeight - menuTop - windHeight)
        {
            // do nothing
        }
        if (menuTop + windHeight == backTop + backHeight)
        {
            this->Menu->Top = windHeight - menuHeight;
            this->Menu->BackColor = System::Drawing::Color::Blue;
        }
        else
        {
            this->Menu->BackColor = System::Drawing::Color::Pink;
        }
    }
    else if (menuTop == 0 && this->backgroundInputZone->Height <= this->backgroundMask->Height)
    {
        this->Menu->Height = this->Height - 39;
    } 
    // preventing problems
    else
    {
        this->Menu->Top = 0;
    }
    /*if (this->backgroundInputZone->Height <= this->backgroundMask->Height)
    {
        this->Menu->Top = 0;
    }*/
    if (this->Menu->Height < this->Height - 39)
    {
        this->Menu->Height = this->Height - 39;
    }

    this->Text = gcnew String((to_string(this->Menu->Top)).c_str());

    // Menu->InputZone
    this->backgroundMask->Size = System::Drawing::Size(windWidh, this->Height - 39 - QzCPP::MainPage::MainWindowHeight * 35 / 100);
    this->backgroundInputZone->Width = windWidh;
    
    // ScrollBar
    this->scrollBar->Height = this->Height - 39;
    this->scrollBar->Location = System::Drawing::Point(windWidh - this->scrollBar->Width, 0);
    // ScrollBar->Handle
    this->handle->Location = System::Drawing::Point(windWidh - this->scrollBar->Width + (this->scrollBar->Width - this->handle->Width) / 2, 0);

    // Learn
    //this->Learn->Size = this->Size;

    // Normal Controls
    ResizeControlers(this->startCard,startCardButton, windWidh);
    ResizeControlers(this->startLearn, startLearnButton, windWidh);
    ResizeControlers(this->startWrite, startWriteButton, windWidh);
    ResizeControlers(this->StartPlusTard, startPlusTardButton, windWidh);

    ResizeControlers(this->bannerLightGrey, bannerLightGreyPanel, windWidh);
    ResizeControlers(this->panelTextBox, panelTextBoxPanel, windWidh);
    ResizeControlers(this->rightTextBox, rightTextBoxTextBox, windWidh);
    ResizeControlers(this->leftTextBox, leftTextBoxTextBox, windWidh);
    ResizeControlers(this->panelRedDarck, panelRedDarckPanel, windWidh);

    if (this->backgroundInputZone->Height > this->backgroundMask->Height)
    {
        this->handle->Show();
        this->scrollBar->Show();
        this->handle->Height = handleSize(this->Height - 39, this->backgroundInputZone->Height, this->backgroundInputZone->Top);
    } else {
        this->handle->Hide();
        this->scrollBar->Hide();
    }
}
System::Void QzCPP::MainPage::showScrollBar()
{
    this->scrollBar->Width = 12;
    this->handle->Width = 8;
    this->scrollBar->Height = this->Height - 39;
    this->scrollBar->Location = System::Drawing::Point(this->Width - 16 - this->scrollBar->Width, 0);
    this->handle->Location = System::Drawing::Point(this->Width - 16 - this->scrollBar->Width + (this->scrollBar->Width - this->handle->Width) / 2, 0);
}
System::Void QzCPP::MainPage::hideScrollBar()
{
    this->scrollBar->Width = 4;
    this->handle->Width = 2;
    this->scrollBar->Height = this->Height - 39;
    this->scrollBar->Location = System::Drawing::Point(this->Width - 16 - this->scrollBar->Width, 0);
    this->handle->Location = System::Drawing::Point(this->Width - 16 - this->scrollBar->Width + (this->scrollBar->Width - this->handle->Width) / 2, 0);
}

[STAThread]

void main() {
    System::Windows::Forms::Application::EnableVisualStyles();
    QzCPP::MainPage form;
    Application::Run(% form);
}