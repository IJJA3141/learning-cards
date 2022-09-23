#include "SetPageTerm.h"
#include "InputZone.h"

namespace QzCPP
{
	ref class Menu : public System::Windows::Forms::Panel
	{
	private:
		System::Windows::Forms::Button^ m_topLeft;
		System::Windows::Forms::Button^ m_topRight;
		System::Windows::Forms::Button^ m_downLeft;
		System::Windows::Forms::Button^ m_downRight;
		QzCPP::InputZone^ m_pageTermBackground;
	private:
		System::ComponentModel::Container^ components;
	public:
		Menu()
		{
			this->m_topLeft = gcnew System::Windows::Forms::Button();
			this->m_topRight = gcnew System::Windows::Forms::Button();
			this->m_downLeft = gcnew System::Windows::Forms::Button();
			this->m_downRight = gcnew System::Windows::Forms::Button();
			this->m_pageTermBackground = gcnew QzCPP::InputZone();

			// startCard
			this->m_topLeft->TabIndex = 1;
			this->m_topLeft->Text = L"Card";

			this->m_topLeft->Size = System::Drawing::Size(200, 80);
			this->m_topLeft->Location = System::Drawing::Point(80, 80);
			//this->m_topLeft->Click += gcnew System::EventHandler(this, &QzCPP::MainPage::addRow);

			// startLearn
			this->m_topRight->TabIndex = 2;
			this->m_topRight->Text = L"Learn";

			this->m_topRight->Size = System::Drawing::Size(200, 80);
			this->m_topRight->Location = System::Drawing::Point(320, 80);
			//this->m_topRight->Click += gcnew System::EventHandler(this, &QzCPP::MainPage::handleClick);

			// startWrite
			this->m_downLeft->TabIndex = 3;
			this->m_downLeft->Text = L"Write";

			this->m_downLeft->Size = System::Drawing::Size(200, 80);
			this->m_downLeft->Location = System::Drawing::Point(80, 200);
			//this->m_downLeft->Click += gcnew System::EventHandler(this, &QzCPP::MainPage::handleClick);

			// StartPlusTard
			this->m_downRight->TabIndex = 4;
			this->m_downRight->Text = L"?";

			this->m_downRight->Size = System::Drawing::Size(200, 80);
			this->m_downRight->Location = System::Drawing::Point(320, 200);
			//this->StartPlusTard->Click += gcnew System::EventHandler(this, &QzCPP::MainPage::handleClick);

			

			// Menu
			this->Location = System::Drawing::Point(0, 0);
			this->Size = System::Drawing::Size(600, 600);

			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->Padding = System::Windows::Forms::Padding(0, 0, 0, 0);
			this->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
			this->TabStop = false;
			this->Name = L"Menu";

			

			this->Controls->Add(this->m_topLeft);
			this->Controls->Add(this->m_topRight);
			this->Controls->Add(this->m_downLeft);
			this->Controls->Add(this->m_downRight);
			this->Controls->Add(this->m_pageTermBackground);
		}
	protected:
		~Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		void ResizeControls(int windowWidth, int windowHeight)
		{
			this->Width = windowWidth;
			this->Height = windowHeight;
		}
	};
}