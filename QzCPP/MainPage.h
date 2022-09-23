#pragma once
#include <Windows.h>
#include "Menu.h"

namespace QzCPP
{
	public ref class MainPage : public System::Windows::Forms::Form
	{
	private:
		QzCPP::Menu^ menu;
		System::Windows::Forms::Panel s;

	public: 
		MainPage(void)
		{
			InitializeComponent();
		}
	protected:
		~MainPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent()
		{
			this->ClientSize = System::Drawing::Size(600, 600);
			this->Size = System::Drawing::Size(616, 639);

			menu = gcnew QzCPP::Menu();
			this->Controls->Add(menu);
			
			this->Name = L"MainPage";
			this->Text = L"QzCPP";
			this->ResumeLayout(false);
			this->Resize += gcnew System::EventHandler(this, &MainPage::MainPageResize);
			//this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &QzCPP::MainPage::OnMouseWheel);
		}
	private:
		System::Void MainPageResize(System::Object^ sender, System::EventArgs^ e);
	};
}