#pragma once
namespace QzCPP
{
	ref class InputZone : public System::Windows::Forms::Panel
	{
	private:
		int m_numberOfSetPageTerm = 0;
	private:
		System::Windows::Forms::Button^ m_buttonAddRow;
		System::Windows::Forms::Panel^ m_greyStyle;
	private:
		System::ComponentModel::Container^ components;
	public:
		InputZone()
		{
			InitializeComponent();
		}
	protected:
		~InputZone()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		void InitializeComponent();
	private:
		System::Void OnClick(System::Object^ sender, System::EventArgs^ e);
		void OnControlRemoved(System::Object^ sender, System::Windows::Forms::ControlEventArgs^ e);
	};
}