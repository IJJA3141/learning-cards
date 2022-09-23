namespace QzCPP
{
	ref class Menu
	{
	private:
		System::Windows::Forms::Panel^ m_menu;

		System::Windows::Forms::Button^ m_topLeft;
		System::Windows::Forms::Button^ m_topRight;
		System::Windows::Forms::Button^ m_downLeft;
		System::Windows::Forms::Button^ m_downRight;
	private:
		System::ComponentModel::Container^ components;
	public:
		Menu()
		{
			this->m_menu = gcnew System::Windows::Forms::Panel();

			this->m_topLeft = gcnew System::Windows::Forms::Button();
			this->m_topRight = gcnew System::Windows::Forms::Button();
			this->m_downLeft = gcnew System::Windows::Forms::Button();
			this->m_downRight = gcnew System::Windows::Forms::Button();

			// startCard
			this->m_topLeft->TabIndex = 1;
			this->m_topLeft->Text = L"Card";
			//this->m_topLeft->Click += gcnew System::EventHandler(this, &QzCPP::MainPage::addRow);

			// startLearn
			this->m_topRight->TabIndex = 2;
			this->m_topRight->Text = L"Learn";
			//this->m_topRight->Click += gcnew System::EventHandler(this, &QzCPP::MainPage::handleClick);

			// startWrite
			this->m_downLeft->TabIndex = 3;
			this->m_downLeft->Text = L"Write";
			//this->m_downLeft->Click += gcnew System::EventHandler(this, &QzCPP::MainPage::handleClick);

			// StartPlusTard
			this->m_downRight->TabIndex = 4;
			this->m_downRight->Text = L"?";
			//this->StartPlusTard->Click += gcnew System::EventHandler(this, &QzCPP::MainPage::handleClick);

			this->m_menu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(19)));
			this->m_menu->Location = System::Drawing::Point(0, 0);
			this->m_menu->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
			this->m_menu->Padding = System::Windows::Forms::Padding(0, 0, 0, 0);
			this->m_menu->TabStop = false;
			this->m_menu->Name = L"Menu";

			this->m_menu->Controls->Add(this->m_topLeft);
			this->m_menu->Controls->Add(this->m_topRight);
			this->m_menu->Controls->Add(this->m_downLeft);
			this->m_menu->Controls->Add(this->m_downLeft);
		}
	protected:
		~Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	};
}