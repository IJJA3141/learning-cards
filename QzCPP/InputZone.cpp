#include "SetPageTerm.h"
#include "InputZone.h"
#include "QzCPPLib.h"

void QzCPP::InputZone::InitializeComponent()
{
	this->m_buttonAddRow = gcnew System::Windows::Forms::Button();
	this->m_greyStyle = gcnew System::Windows::Forms::Panel();
	this->ControlRemoved += gcnew System::Windows::Forms::ControlEventHandler(this, &QzCPP::InputZone::OnControlRemoved);

	// AddRow
	this->m_buttonAddRow->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
	this->m_buttonAddRow->Size = System::Drawing::Size(85, 35);
	this->m_buttonAddRow->Location = System::Drawing::Point(512, 3);
	this->m_buttonAddRow->Click += gcnew System::EventHandler(this, &QzCPP::InputZone::OnClick);

	// pageTermeBackground
	this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
	this->Location = System::Drawing::Point(0, 300);
	this->Size = System::Drawing::Size(600, 300);

	// greyStyle
	this->m_greyStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
	this->m_greyStyle->Location = System::Drawing::Point(0, 0);
	this->m_greyStyle->Size = System::Drawing::Size(600, 41);

	this->m_greyStyle->Controls->Add(this->m_buttonAddRow);

	this->Controls->Add(this->m_greyStyle);
	this->Controls->Add(gcnew QzCPP::SetPageTerm(m_numberOfSetPageTerm, "test", "test"));
}

System::Void QzCPP::InputZone::OnClick(System::Object^ sender, System::EventArgs^ e)
{
	m_numberOfSetPageTerm += 1;
	this->Controls->Add(gcnew QzCPP::SetPageTerm(m_numberOfSetPageTerm, "", ""));
}


void QzCPP::InputZone::OnControlRemoved(System::Object^ sender, System::Windows::Forms::ControlEventArgs^ e)
{
	this->m_numberOfSetPageTerm -= 1;
}
