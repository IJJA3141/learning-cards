#include "InputZone.h"
#include "SetPageTerm.h"

void QzCPP::SetPageTerm::InitializeComponent(int numberOfSetPageTerm, std::string term, std::string definition)
{
	{
		this->m_numberOfSetPageTerm = numberOfSetPageTerm;

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
		this->m_redStyle->Size = System::Drawing::Size(500, 1);
		this->m_redStyle->Location = System::Drawing::Point(0, 37);

		// deleteButton
		this->m_deleteButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
		this->m_deleteButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
		this->m_deleteButton->Size = System::Drawing::Size(70, 25);
		this->m_deleteButton->Location = System::Drawing::Point(424, 6);
		this->m_deleteButton->Click += gcnew System::EventHandler(this, &QzCPP::SetPageTerm::Del);

		// leftTextBoxPanel
		this->m_leftTextBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
		this->m_leftTextBoxPanel->Size = System::Drawing::Size(225, 5);
		this->m_leftTextBoxPanel->Location = System::Drawing::Point(10, 102);

		// rightTextBoxPanel
		this->m_rightTextBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
		this->m_rightTextBoxPanel->Size = System::Drawing::Size(225, 5);
		this->m_rightTextBoxPanel->Location = System::Drawing::Point(265, 102);

		// leftTextBox
		this->m_leftTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
		this->m_leftTextBox->Multiline = true;
		this->m_leftTextBox->BorderStyle = System::Windows::Forms::BorderStyle(0);
		this->m_leftTextBox->Size = System::Drawing::Size(225, 35);
		this->m_leftTextBox->Location = System::Drawing::Point(10, 65);
		this->m_leftTextBox->GotFocus += gcnew System::EventHandler(this, &QzCPP::SetPageTerm::OnLeftTextBoxGotFocus);
		this->m_leftTextBox->LostFocus += gcnew System::EventHandler(this, &QzCPP::SetPageTerm::OnLeftTextBoxLostFocus);
		this->m_leftTextBox->TextChanged += gcnew System::EventHandler(this, &QzCPP::SetPageTerm::NewLine);

		// rightTextBox
		this->m_rightTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
		this->m_rightTextBox->Multiline = true;
		this->m_rightTextBox->BorderStyle = System::Windows::Forms::BorderStyle(0);
		this->m_rightTextBox->Size = System::Drawing::Size(225, 35);
		this->m_rightTextBox->Location = System::Drawing::Point(265, 65);
		this->m_rightTextBox->GotFocus += gcnew System::EventHandler(this, &QzCPP::SetPageTerm::OnRightTextBoxGotFocus);
		this->m_rightTextBox->LostFocus += gcnew System::EventHandler(this, &QzCPP::SetPageTerm::OnRightTextBoxLostFocus);

		this->m_rightTextBox->Font = (gcnew System::Drawing::Font(L"M PLUS Rounded 1c", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(256)));
		this->m_rightTextBox->ForeColor = System::Drawing::SystemColors::Window;

		// index
		this->m_index->Text = gcnew System::String(std::to_string(numberOfSetPageTerm).c_str());
		this->m_index->TextChanged += gcnew System::EventHandler(this, &QzCPP::SetPageTerm::OnTextChanged);

		this->Controls->Add(this->m_index);
		this->Controls->Add(this->m_leftTextBox);
		this->Controls->Add(this->m_rightTextBox);
		this->Controls->Add(this->m_deleteButton);
		this->Controls->Add(this->m_redStyle);
		this->Controls->Add(this->m_leftTextBoxPanel);
		this->Controls->Add(this->m_rightTextBoxPanel);
	}
}

System::Void QzCPP::SetPageTerm::OnLeftTextBoxGotFocus(System::Object^ sender, System::EventArgs^ e)
{

	this->m_leftTextBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
	this->m_leftTextBoxPanel->Size = System::Drawing::Size(this->m_leftTextBoxPanel->Width + 4, this->m_leftTextBoxPanel->Height + 2);
	this->m_leftTextBoxPanel->Left -= 2;

}
System::Void QzCPP::SetPageTerm::OnLeftTextBoxLostFocus(System::Object^ sender, System::EventArgs^ e)
{
	this->m_leftTextBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
	this->m_leftTextBoxPanel->Size = System::Drawing::Size(this->m_leftTextBoxPanel->Width - 4, this->m_leftTextBoxPanel->Height - 2);
	this->m_leftTextBoxPanel->Left += 2;
}

System::Void QzCPP::SetPageTerm::OnRightTextBoxGotFocus(System::Object^ sender, System::EventArgs^ e)
{
	this->m_rightTextBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
	this->m_rightTextBoxPanel->Size = System::Drawing::Size(this->m_rightTextBoxPanel->Width + 4, this->m_rightTextBoxPanel->Height + 2);
	this->m_rightTextBoxPanel->Left -= 2;
}
System::Void QzCPP::SetPageTerm::OnRightTextBoxLostFocus(System::Object^ sender, System::EventArgs^ e)
{
	this->m_rightTextBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
	this->m_rightTextBoxPanel->Size = System::Drawing::Size(this->m_rightTextBoxPanel->Width - 4, this->m_rightTextBoxPanel->Height - 2);
	this->m_rightTextBoxPanel->Left += 2;
}

System::Void QzCPP::SetPageTerm::Del(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = this->m_numberOfSetPageTerm; i < this->Parent->Controls->Count - 1; i++)
	{
		this->Parent->Controls[i + 1]->Top = 61 + 131 * (i - 1);
		this->Parent->Controls[i + 1]->Controls[0]->Text = gcnew System::String(std::to_string(i - 1).c_str());
	}

	delete this;
}

void QzCPP::SetPageTerm::OnTextChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->m_numberOfSetPageTerm -= 1;
}


void QzCPP::SetPageTerm::NewLine(System::Object^ sender, System::EventArgs^ e)
{
	this->m_rightTextBox;
	this->m_leftTextBox;
	this->m_leftTextBoxPanel;
	this->m_rightTextBox;
	//this->;
}