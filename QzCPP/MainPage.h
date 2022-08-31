#pragma once

namespace QzCPP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MainPage
	/// </summary>
	public ref class MainPage : public System::Windows::Forms::Form
	{
	public: int NumberOfLine = 1;
	public: int pos = 258;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	public: int posIncr = 200;

	public:
		MainPage(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			Populate();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MainPage()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Panel^ backgroundDG;
	private: System::Windows::Forms::Panel^ bannerLG;

	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Panel^ panelTB1;

	private: System::Windows::Forms::Panel^ leftPP1;
	private: System::Windows::Forms::TextBox^ leftTB1;

	private: System::Windows::Forms::Panel^ panelRD1;

	private: System::Windows::Forms::Panel^ rightPP1;
	private: System::Windows::Forms::TextBox^ rightTB1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->backgroundDG = (gcnew System::Windows::Forms::Panel());
			this->rightTB1 = (gcnew System::Windows::Forms::TextBox());
			this->leftTB1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panelTB1 = (gcnew System::Windows::Forms::Panel());
			this->panelRD1 = (gcnew System::Windows::Forms::Panel());
			this->rightPP1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->bannerLG = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->leftPP1 = (gcnew System::Windows::Forms::Panel());
			this->backgroundDG->SuspendLayout();
			this->panelTB1->SuspendLayout();
			this->rightPP1->SuspendLayout();
			this->leftPP1->SuspendLayout();
			this->SuspendLayout();
			// 
			// backgroundDG
			// 
			this->backgroundDG->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->backgroundDG->Margin = System::Windows::Forms::Padding(0);
			this->backgroundDG->Location = System::Drawing::Point(0, 377);
			this->backgroundDG->Size = System::Drawing::Size(3168, 1279);
			this->backgroundDG->Controls->Add(this->panelTB1);
			this->backgroundDG->Controls->Add(this->bannerLG);
			this->backgroundDG->Controls->Add(this->button2);
			this->backgroundDG->Controls->Add(this->button1);
			this->backgroundDG->Name = L"backgroundDG";
			this->backgroundDG->AutoScroll = true;
			this->backgroundDG->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->button2->Click += gcnew System::EventHandler(this, &MainPage::Test);
			this->button2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Location = System::Drawing::Point(2788, 375);
			this->button2->Size = System::Drawing::Size(280, 150);
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Name = L"button2";
			this->button2->Text = L"Test";
			this->button2->TabIndex = 2;
			// 
			// panelTB1
			// 
			this->panelTB1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->panelTB1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainPage::panel4_Paint);
			this->panelTB1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTB1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->panelTB1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panelTB1->Location = System::Drawing::Point(480, 496);
			this->panelTB1->Size = System::Drawing::Size(2238, 98);
			this->panelTB1->Controls->Add(this->panelRD1);
			this->panelTB1->Controls->Add(this->rightPP1);
			this->panelTB1->Controls->Add(this->leftPP1);
			this->panelTB1->Name = L"panelTB1";
			this->panelTB1->TabIndex = 1;
			// 
			// panelRD1
			// 
			this->panelRD1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->panelRD1->Location = System::Drawing::Point(1114, 12);
			this->panelRD1->Margin = System::Windows::Forms::Padding(0);
			this->panelRD1->Size = System::Drawing::Size(12, 77);
			this->panelRD1->Name = L"panelRD1";
			this->panelRD1->TabIndex = 3;
			// 
			// rightPP1
			// 
			this->rightPP1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->rightPP1->Margin = System::Windows::Forms::Padding(0);
			this->rightPP1->Location = System::Drawing::Point(1126, 0);
			this->rightPP1->Size = System::Drawing::Size(1114, 96);
			this->rightPP1->Controls->Add(this->rightTB1);
			this->rightPP1->Name = L"rightPP1";
			this->rightPP1->TabIndex = 2;
			// 
			// rightTB1
			// 
			this->rightTB1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->rightTB1->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
			this->rightTB1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rightTB1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->rightTB1->ForeColor = System::Drawing::SystemColors::Window;
			this->rightTB1->Margin = System::Windows::Forms::Padding(0);
			this->rightTB1->Location = System::Drawing::Point(20, 17);
			this->rightTB1->Size = System::Drawing::Size(1074, 63);
			this->rightTB1->Name = L"rightTB1";
			this->rightTB1->TabIndex = 0;
			// 
			// leftPP1
			// 
			this->leftPP1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->leftPP1->Margin = System::Windows::Forms::Padding(0);
			this->leftPP1->Location = System::Drawing::Point(0, 0);
			this->leftPP1->Size = System::Drawing::Size(1114, 96);
			this->leftPP1->Controls->Add(this->leftTB1);
			this->leftPP1->Name = L"leftPP1";
			this->leftPP1->TabIndex = 1;
			// 
			// leftTB1
			// 
			this->leftTB1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->leftTB1->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
			this->leftTB1->TextChanged += gcnew System::EventHandler(this, &MainPage::leftTB1_TextChanged);
			this->leftTB1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->leftTB1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->leftTB1->ForeColor = System::Drawing::SystemColors::Window;
			this->leftTB1->Margin = System::Windows::Forms::Padding(0);
			this->leftTB1->Location = System::Drawing::Point(20, 17);
			this->leftTB1->Size = System::Drawing::Size(1074, 63);
			this->leftTB1->Name = L"leftTB1";
			this->leftTB1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->button1->Click += gcnew System::EventHandler(this, &MainPage::AddRow);
			this->button1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Location = System::Drawing::Point(2788, 213);
			this->button1->Size = System::Drawing::Size(280, 150);
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Name = L"button1";
			this->button1->Text = L"button1";
			this->button1->TabIndex = 1;
			// 
			// bannerLG
			// 
			this->bannerLG->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->bannerLG->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->bannerLG->Margin = System::Windows::Forms::Padding(0);
			this->bannerLG->Location = System::Drawing::Point(0, 31);
			this->bannerLG->Size = System::Drawing::Size(3200, 96);
			this->bannerLG->Name = L"bannerLG";
			this->bannerLG->TabIndex = 0;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1101, 32);
			this->button3->Size = System::Drawing::Size(219, 114);
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Name = L"button3";
			this->button3->Text = L"Learn";
			this->button3->TabIndex = 3;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1839, 32);
			this->button4->Size = System::Drawing::Size(219, 114);
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Name = L"button4";
			this->button4->Text = L"Test";
			this->button4->TabIndex = 4;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(1101, 212);
			this->button5->Size = System::Drawing::Size(219, 114);
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Name = L"button5";
			this->button5->Text = L"Cards";
			this->button5->TabIndex = 5;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(1839, 212);
			this->button6->Size = System::Drawing::Size(219, 114);
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Name = L"button6";
			this->button6->Text = L"futur";
			this->button6->TabIndex = 6;
			// 
			// MainPage
			// 
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->Closed += gcnew System::EventHandler(this, &MainPage::OnFormClosing);
			this->Load += gcnew System::EventHandler(this, &MainPage::MainPage_Load);
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->ClientSize = System::Drawing::Size(2884, 1656);
			this->backgroundDG->ResumeLayout(false);
			this->Controls->Add(this->backgroundDG);
			this->panelTB1->ResumeLayout(false);
			this->rightPP1->ResumeLayout(false);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->leftPP1->ResumeLayout(false);
			this->rightPP1->PerformLayout();
			this->leftPP1->PerformLayout();
			this->ResumeLayout(false);
			this->Name = L"MainPage";
			this->Text = L"MainPage";
			this->AutoScroll = true;

		}

#pragma endregion
	private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
	}
	private: System::Void treeView1_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
	}
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void tableLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void rightTB1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void leftTB1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void groupBox4_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MainPage_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void OnFormClosing(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddRow(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Test(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Populate();
};
}
