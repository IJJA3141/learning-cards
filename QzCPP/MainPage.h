#pragma once
#include <Windows.h>

namespace QzCPP
{
	public ref class MainPage : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::Panel^ Menu;

	public: 
		MainPage(void)
		{
			InitializeMyComponent();
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

		void InitializeMyComponent()
		{
			this->Menu = gcnew System::Windows::Forms::Panel();

			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->Name = L"MainPage";
			this->Text = L"QzCPP";
			this->Menu->ResumeLayout(false);
			this->ResumeLayout(false);
			this->Resize += gcnew System::EventHandler(this, &MainPage::MainPageResize);
			//this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &QzCPP::MainPage::OnMouseWheel);
		}
	private:
		System::Void MainPageResize(System::Object^ sender, System::EventArgs^ e);
	};
}