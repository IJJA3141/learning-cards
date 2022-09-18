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

int aaaaa(int Top)
{
    if (Top < 0)
    {
        return std::abs(Top);
    } else {
        return 0;
    }
}

System::Void QzCPP::MainPage::ResizeAll()
{ 
    // Special Things
    int tempWidh = this->Width - 16;

    // Menu
    this->backgroundMask->Size = System::Drawing::Size(tempWidh, this->Height - 39 - QzCPP::MainPage::MainWindowHeight * 35 / 100);
    // Menu->InputZone
    this->backgroundInputZone->Width = tempWidh;
    
    // ScrollBar
    this->scrollBar->Height = this->Height - 39;
    this->scrollBar->Location = System::Drawing::Point(tempWidh - this->scrollBar->Width, 0);
    // ScrollBar->Handle
    this->handle->Location = System::Drawing::Point(tempWidh - this->scrollBar->Width + (this->scrollBar->Width - this->handle->Width) / 2, 0);

    // Learn
    //this->Learn->Size = this->Size;

    // Normal Controls
    ResizeControlers(this->startCard,startCardButton, tempWidh);
    ResizeControlers(this->startLearn, startLearnButton, tempWidh);
    ResizeControlers(this->startWrite, startWriteButton, tempWidh);
    ResizeControlers(this->StartPlusTard, startPlusTardButton, tempWidh);

    ResizeControlers(this->bannerLightGrey, bannerLightGreyPanel, tempWidh);
    ResizeControlers(this->panelTextBox, panelTextBoxPanel, tempWidh);
    ResizeControlers(this->rightTextBox, rightTextBoxTextBox, tempWidh);
    ResizeControlers(this->leftTextBox, leftTextBoxTextBox, tempWidh);
    ResizeControlers(this->panelRedDarck, panelRedDarckPanel, tempWidh);

    if (this->backgroundInputZone->Height > this->backgroundMask->Height)
    {
        this->handle->Show();
        this->scrollBar->Show();
        this->handle->Height = handleSize(this->Height - 39, this->backgroundInputZone->Height, this->backgroundInputZone->Top);
        this->Menu->Size = System::Drawing::Size(tempWidh, aaaaa(this->Menu->Top) + this->backgroundInputZone->Top + this->backgroundInputZone->Height);
    } else {
        this->handle->Hide();
        this->scrollBar->Hide();
        this->Menu->Size = System::Drawing::Size(tempWidh, aaaaa(this->Menu->Top) + this->Height - 39);
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