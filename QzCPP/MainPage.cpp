#include "MainPage.h"

System::Void QzCPP::MainPage::MainPageResize(System::Object^ sender, System::EventArgs^ e)
{
	menu->ResizeControls(this->Width, this->Height);
}

