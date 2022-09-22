#pragma once

namespace QzCPP {

	public ref class MyScrollBar
	{
	private:
		System::Windows::Forms::Panel^ scrollBar;
		System::Windows::Forms::Button^ handle;
	public:
		System::Void ScrollBar(int scrollBarHeight, int scrollBarWidth)
		{
			scrollBar = gcnew System::Windows::Forms::Panel();
			handle = gcnew System::Windows::Forms::Button();

			this->scrollBar->Size = System::Drawing::Size(12, scrollBarHeight);
			this->scrollBar->Location = System::Drawing::Point(scrollBarWidth - this->scrollBar->Width, 0);
			this->scrollBar->Name = L"scrollBar";
			this->scrollBar->TabStop = false;
			this->scrollBar->MouseEnter += gcnew System::EventHandler(this, &MyScrollBar::ScrollBarMaximize);
			this->scrollBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));

			this->handle->Size = System::Drawing::Size(8, 15);
			this->handle->Location = System::Drawing::Point(scrollBarWidth - this->scrollBar->Width + (this->scrollBar->Width - this->handle->Width) / 2, 0);
			this->handle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(119)), static_cast<System::Int32>(static_cast<System::Byte>(119)), static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->handle->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->handle->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
			this->handle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->handle->UseVisualStyleBackColor = false;
			this->handle->FlatAppearance->BorderSize = 0;
			this->handle->Click += gcnew System::EventHandler(this, &MyScrollBar::handleClick);
			this->handle->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyScrollBar::onButtonMouseDown);
			this->handle->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyScrollBar::onButtonMouseUp);
		}
	private:
		System::Void ScrollBarMaximize(System::Object^ sender, System::EventArgs^ e);
	public:
		System::Void ScrollBarMinimize(System::Object^ sender, System::EventArgs^ e);
	public:
		System::Void ScrollBarShow();
	public:
		System::Void ScrollBarHide();
	public:
		System::Void HandlePosition(int backgroundHeight, int backgroundTop);




	public:
		System::Void ResizeScrollBar();
	private: System::Void scrollBarMouseLeave(System::Object^ sender, System::EventArgs^ e) {
		hideScrollBar();
	}
	private: System::Void handleClick(System::Object^ sender, System::EventArgs^ e) {
		if (this->Menu->Height - this->Height - 39 + this->Menu->Top >= 1)
		{
			this->Menu->Top -= 1;
		}
		else
		{
			//this->Menu->Top -= this->Menu->Height - this->Height + 39;
		}
	}
	private: System::Void OnMouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		aaaaaaaaa(e->Delta);
	}
	private: System::Void MainPage_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->Text = gcnew String((std::to_string(e->Y)).c_str());
	}
	private: System::Void onButtonMouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		for (int i = 0; i < this->Controls->Count; i++)
		{
			this->Controls[i]->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainPage::MainPage_MouseMove);
		}
	}
	private: System::Void onButtonMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		for (int i = 0; i < this->Controls->Count; i++)
		{
			this->Controls[i]->MouseMove -= gcnew System::Windows::Forms::MouseEventHandler(this, &MainPage::MainPage_MouseMove);
		}
	}
	public: System::Void ResizeAll();
	public: System::Void showScrollBar();
	public: System::Void hideScrollBar();
	private: System::Void aaaaaaaaa(int scroll)
	{
		if (scroll < 0)
		{
			if (this->Menu->Height + this->Menu->Top - this->Height + 39 > 60 * scroll / 120)
			{
				this->Menu->Top += 30 * scroll / 120;
			}
			else
			{
				this->Menu->Top -= this->Menu->Height + this->Menu->Top - this->Height + 39;
			}
		}
		else if (scroll > 0)
		{
			if (this->Menu->Top < 30 * scroll / 120)
			{
				this->Menu->Top += 30 * scroll / 120;
			}
			else
			{
				this->Menu->Top -= this->Menu->Top * scroll / 120;
			}
		}
		ResizeAll();
	}
	};
}