#include <string>

#pragma once
namespace QzCPP
{
	ref class SetPageTerm : public System::Windows::Forms::Panel
	{
	private:
		System::Windows::Forms::Label^ m_index;

		System::Windows::Forms::Button^ m_deleteButton;

		System::Windows::Forms::Panel^ m_redStyle;

		System::Windows::Forms::Panel^ m_leftTextBoxPanel;
		System::Windows::Forms::Panel^ m_rightTextBoxPanel;

		System::Windows::Forms::TextBox^ m_leftTextBox;
		System::Windows::Forms::TextBox^ m_rightTextBox;
	public:
		SetPageTerm(int numberOfSetPageTerm, std::string term, std::string definition)
		{
			InitializeComponent(numberOfSetPageTerm - 1, term, definition);
		}
	protected:
		~SetPageTerm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(int numberOfSetPageTerm, std::string term, std::string definition)
		{
			this->m_index = gcnew System::Windows::Forms::Label();

			this->m_deleteButton = gcnew System::Windows::Forms::Button();

			this->m_redStyle = gcnew System::Windows::Forms::Panel();

			this->m_leftTextBoxPanel = gcnew System::Windows::Forms::Panel();
			this->m_rightTextBoxPanel = gcnew System::Windows::Forms::Panel();

			this->m_leftTextBox = gcnew System::Windows::Forms::TextBox();
			this->m_rightTextBox = gcnew System::Windows::Forms::TextBox();

			// this
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->Size = System::Drawing::Size(500, 117);
			this->Location = System::Drawing::Point(50, 61 + 131 * numberOfSetPageTerm);

			// redStyle
			this->m_redStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->m_redStyle->Size = System::Drawing::Size(500, 4);
			this->m_redStyle->Location = System::Drawing::Point(0, 37);

			// deleteButton
			this->m_deleteButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->m_deleteButton->Size = System::Drawing::Size(70, 25);
			this->m_deleteButton->Location = System::Drawing::Point(424, 6);

			// leftTextBoxPanel
			this->m_leftTextBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->m_leftTextBoxPanel->Size = System::Drawing::Size(225, 5);
			this->m_leftTextBoxPanel->Location = System::Drawing::Point(10, 102);

			// rightTextBoxPanel
			this->m_rightTextBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->m_rightTextBoxPanel->Size = System::Drawing::Size(225, 5);
			this->m_rightTextBoxPanel->Location = System::Drawing::Point(265, 102);

			// leftTextBox
			this->m_leftTextBox->Size = System::Drawing::Size(225, 45);
			this->m_leftTextBox->Location = System::Drawing::Point(10, 55);
			this->m_leftTextBox->GotFocus += gcnew System::EventHandler(this, &QzCPP::SetPageTerm::OnLeftTextBoxGotFocus);
			this->m_leftTextBox->LostFocus += gcnew System::EventHandler(this, &QzCPP::SetPageTerm::OnLeftTextBoxLostFocus);

			// rightTextBox
			this->m_rightTextBox->Size = System::Drawing::Size(225, 45);
			this->m_rightTextBox->Location = System::Drawing::Point(265, 55);
			this->m_rightTextBox->GotFocus += gcnew System::EventHandler(this, &QzCPP::SetPageTerm::OnRightTextBoxGotFocus);
			this->m_rightTextBox->LostFocus += gcnew System::EventHandler(this, &QzCPP::SetPageTerm::OnRightTextBoxLostFocus);

			this->Controls->Add(this->m_leftTextBox);
			this->Controls->Add(this->m_rightTextBox);
			this->Controls->Add(this->m_index);
			this->Controls->Add(this->m_deleteButton);
			this->Controls->Add(this->m_redStyle);
			this->Controls->Add(this->m_leftTextBoxPanel);
			this->Controls->Add(this->m_rightTextBoxPanel);
		}
	private:
		System::Void OnLeftTextBoxGotFocus(System::Object^ sender, System::EventArgs^ e)
		{
			this->m_leftTextBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->m_leftTextBoxPanel->Size = System::Drawing::Size(this->m_leftTextBoxPanel->Width + 4, this->m_leftTextBoxPanel->Height + 2);
			this->m_leftTextBoxPanel->Left -= 2;
		}
		System::Void OnLeftTextBoxLostFocus(System::Object^ sender, System::EventArgs^ e)
		{
			this->m_leftTextBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->m_leftTextBoxPanel->Size = System::Drawing::Size(this->m_leftTextBoxPanel->Width - 4, this->m_leftTextBoxPanel->Height - 2);
			this->m_leftTextBoxPanel->Left += 2;
		}
		System::Void OnRightTextBoxGotFocus(System::Object^ sender, System::EventArgs^ e)
		{
			this->m_rightTextBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->m_rightTextBoxPanel->Size = System::Drawing::Size(this->m_rightTextBoxPanel->Width + 4, this->m_rightTextBoxPanel->Height + 2);
			this->m_rightTextBoxPanel->Left -= 2;
		}
		System::Void OnRightTextBoxLostFocus(System::Object^ sender, System::EventArgs^ e)
		{
			this->m_rightTextBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->m_rightTextBoxPanel->Size = System::Drawing::Size(this->m_rightTextBoxPanel->Width - 4, this->m_rightTextBoxPanel->Height - 2);
			this->m_rightTextBoxPanel->Left += 2;
		}
	};
}