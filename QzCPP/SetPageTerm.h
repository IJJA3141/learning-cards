#include <string>

#pragma once
namespace QzCPP
{
	ref class SetPageTerm : public System::Windows::Forms::Panel
	{
	private:
		int v1;
		int v2;
	private:
		int m_numberOfSetPageTerm;
		int m_leftTextBound = -2;
		int m_rightTextBound = 10;
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
			InitializeComponent(numberOfSetPageTerm, term, definition);
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

		void InitializeComponent(int numberOfSetPageTerm, std::string term, std::string definition);
	private:
		System::Void OnLeftTextBoxGotFocus(System::Object^ sender, System::EventArgs^ e);
		System::Void OnLeftTextBoxLostFocus(System::Object^ sender, System::EventArgs^ e);

		System::Void OnRightTextBoxGotFocus(System::Object^ sender, System::EventArgs^ e);
		System::Void OnRightTextBoxLostFocus(System::Object^ sender, System::EventArgs^ e);
	private:
		System::Void Del(System::Object^ sender, System::EventArgs^ e);
		void OnTextChanged(System::Object^ sender, System::EventArgs^ e);
		//void NewLine(System::Object^ sender, System::EventArgs^ e);
	};
}