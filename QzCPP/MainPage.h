#pragma once
#include <Windows.h>

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
	public: int RightAns;
	public: int NumberOfLine = 1;
	public: int pos = 258;
	public: int posIncr = 200;
	public: static int MainWindowWidth;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	public:
	public: static int MainWindowHeight;

	public:
		MainPage(void)
		{
			//InitializeComponent();
			InitializeMyComponent();
			//this->Learn->Hide();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			//Populate();
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
	private: System::Windows::Forms::Button^ startCard;
	public: System::Drawing::Rectangle startCardButton;

	private: System::Windows::Forms::Button^ startLearn;
	public: System::Drawing::Rectangle startLearnButton;

	private: System::Windows::Forms::Button^ startWrite;
	public: System::Drawing::Rectangle startWriteButton;

	private: System::Windows::Forms::Button^ StartPlusTard;
	public: System::Drawing::Rectangle startPlusTardButton;

	private: System::Windows::Forms::Panel^ backgroundInputZone;
	public: System::Drawing::Rectangle backgroundInputZonePanel;
	
	private: System::Windows::Forms::Panel^ backgroundMask;
	public: System::Drawing::Rectangle backgroundMaskPanel;

	private: System::Windows::Forms::Panel^ bannerLightGrey;
	public: System::Drawing::Rectangle bannerLightGreyPanel;

	private: System::Windows::Forms::Panel^ panelRedDarck;
	public: System::Drawing::Rectangle panelRedDarckPanel;

	private: System::Windows::Forms::Panel^ panelTextBox;
	public: System::Drawing::Rectangle panelTextBoxPanel;

	private: System::Windows::Forms::TextBox^ leftTextBox;
	public: System::Drawing::Rectangle leftTextBoxTextBox;

	private: System::Windows::Forms::TextBox^ rightTextBox;
	public: System::Drawing::Rectangle rightTextBoxTextBox;
		  //
		  //
		  //
	private: System::Windows::Forms::Panel^ Menu;
		  //
		  //
		  //
	private: System::Windows::Forms::Panel^ scrollBar;
	private: System::Windows::Forms::Panel^ handle;

		   /*
		   private: System::Windows::Forms::Panel^ Learn;

		   private: System::Windows::Forms::Button^ button1;

		   private: System::Windows::Forms::Panel^ panelTB1;

		   private: System::Windows::Forms::Panel^ leftPP1;
		   private: System::Windows::Forms::TextBox^ leftTB1;

		   private: System::Windows::Forms::Panel^ panelRD1;

		   private: System::Windows::Forms::Panel^ rightPP1;
		   private: System::Windows::Forms::TextBox^ rightTB1;
		   private: System::Windows::Forms::Button^ button2;
		   */

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

		void InitializeMyComponent(void)
		{
			this->ClientSize = System::Drawing::Size(1920, 1080);
			this->MinimumSize = System::Drawing::Size(400, 500);

			MainWindowWidth = this->Width;
			MainWindowHeight = this->Height;

			this->startCard = (gcnew System::Windows::Forms::Button());
			this->startLearn = (gcnew System::Windows::Forms::Button());
			this->startWrite = (gcnew System::Windows::Forms::Button());
			this->StartPlusTard = (gcnew System::Windows::Forms::Button());

			this->backgroundInputZone = (gcnew System::Windows::Forms::Panel());
			this->backgroundMask = (gcnew System::Windows::Forms::Panel());
			this->bannerLightGrey = (gcnew System::Windows::Forms::Panel());
			this->panelTextBox = (gcnew System::Windows::Forms::Panel());
			this->panelRedDarck = (gcnew System::Windows::Forms::Panel());

			this->leftTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rightTextBox = (gcnew System::Windows::Forms::TextBox());

			this->Menu = (gcnew System::Windows::Forms::Panel());

			this->scrollBar = (gcnew System::Windows::Forms::Panel());
			this->handle = (gcnew System::Windows::Forms::Panel());


			// startCard
			this->startCard->Location = System::Drawing::Point((MainWindowWidth / 2) - 100 - 120, 200 - 50);
			this->startCard->Size = System::Drawing::Size(120, 60);
			this->startCard->TabIndex = 1;
			this->startCard->Text = L"Card";
			startCardButton = System::Drawing::Rectangle(this->startCard->Left, this->startCard->Top, this->startCard->Width, this->startCard->Height);

			// startLearn
			this->startLearn->Location = System::Drawing::Point((MainWindowWidth / 2) + 100, 200 - 50);
			this->startLearn->Size = System::Drawing::Size(120, 60);
			this->startLearn->TabIndex = 2;
			this->startLearn->Text = L"Learn";
			startLearnButton = System::Drawing::Rectangle(this->startLearn->Left, this->startLearn->Top, this->startLearn->Width, this->startLearn->Height);

			// startWrite
			this->startWrite->Location = System::Drawing::Point((MainWindowWidth / 2) - 100 - 120, 360 - 50);
			this->startWrite->Size = System::Drawing::Size(120, 60);
			this->startWrite->TabIndex = 3;
			this->startWrite->Text = L"Write";
			startWriteButton = System::Drawing::Rectangle(this->startWrite->Left, this->startWrite->Top, this->startWrite->Width, this->startWrite->Height);

			// StartPlusTard
			this->StartPlusTard->Location = System::Drawing::Point((MainWindowWidth / 2) + 100, 360 - 50);
			this->StartPlusTard->Size = System::Drawing::Size(120, 60);
			this->StartPlusTard->TabIndex = 4;
			this->StartPlusTard->Text = L"?";
			startPlusTardButton = System::Drawing::Rectangle(this->StartPlusTard->Left, this->StartPlusTard->Top, this->StartPlusTard->Width, this->StartPlusTard->Height);

			// Menu
			this->Menu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->Menu->Size = System::Drawing::Size(MainWindowWidth, MainWindowHeight);
			this->Menu->Location = System::Drawing::Point(0, 0);
			this->Menu->Margin = System::Windows::Forms::Padding(0, 0, 0 , 0);
			this->Menu->TabStop = false;
			this->Menu->Name = L"Menu";

			// scrollBar
			//this->scrollBar->Dock = System::Windows::Forms::DockStyle::Right;
			this->scrollBar->Size = System::Drawing::Size(15, MainWindowHeight);
			this->scrollBar->Location = System::Drawing::Point(0, 0);
			this->scrollBar->Name = L"flowLayoutPanel1";
			this->scrollBar->Size = System::Drawing::Size(53, 147);
			this->scrollBar->TabStop = false;

			// backgroundMask
			this->backgroundMask->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->backgroundMask->Location = System::Drawing::Point(0, MainWindowHeight * 35 / 100);
			this->backgroundMask->Name = L"backgroundInputZone";
			this->backgroundMask->Size = System::Drawing::Size(MainWindowWidth, MainWindowHeight * 65 / 100);
			this->backgroundMask->TabStop = false;
			this->backgroundMask->AutoSize = true;
			this->backgroundMaskPanel = System::Drawing::Rectangle(this->backgroundMask->Left, this->backgroundMask->Top, this->backgroundMask->Width, this->backgroundMask->Height);

			// backgroundInputZone
			this->backgroundInputZone->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->backgroundInputZone->Location = System::Drawing::Point(0, MainWindowHeight * 35 / 100);
			this->backgroundInputZone->Name = L"backgroundInputZone";
			this->backgroundInputZone->Size = System::Drawing::Size(MainWindowWidth, 211);
			this->backgroundInputZone->TabStop = false;
			this->backgroundInputZone->AutoSize = true;
			this->backgroundInputZone->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
			this->backgroundInputZonePanel = System::Drawing::Rectangle(this->backgroundInputZone->Left, this->backgroundInputZone->Top, this->backgroundInputZone->Width, this->backgroundInputZone->Height);

			//bannerLightGrey
			this->bannerLightGrey->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->bannerLightGrey->Location = System::Drawing::Point(0, 16);
			this->bannerLightGrey->Name = L"bannerLightGrey";
			this->bannerLightGrey->Size = System::Drawing::Size(MainWindowWidth, 25);
			this->bannerLightGrey->TabStop = false;
			this->bannerLightGrey->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
			this->bannerLightGreyPanel = System::Drawing::Rectangle(this->bannerLightGrey->Left, this->bannerLightGrey->Top, this->bannerLightGrey->Width, this->bannerLightGrey->Height);

			// panelTextbox
			this->panelTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->panelTextBox->Name = L"panelTextbox1";
			this->panelTextBox->Size = System::Drawing::Size(this->backgroundInputZone->Width*65/100, 45);
			this->panelTextBox->Location = System::Drawing::Point((MainWindowWidth / 2) - (this->panelTextBox->Width / 2), 100);
			this->panelTextBoxPanel = System::Drawing::Rectangle(this->panelTextBox->Left, this->panelTextBox->Top, this->panelTextBox->Width, this->panelTextBox->Height);
			
			// leftTextBox
			this->leftTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->leftTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->leftTextBox->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
			this->leftTextBox->ForeColor = System::Drawing::SystemColors::Window;
			this->leftTextBox->Name = L"leftTextBox1";

			this->leftTextBox->Location = System::Drawing::Point(0, this->panelTextBox->Height * 5 / 100);
			this->leftTextBox->Size = System::Drawing::Size(this->panelTextBox->Width * 45 / 100, this->panelTextBox->Height * 90 / 100);
			this->leftTextBox->TabIndex = 5;
			this->leftTextBoxTextBox = System::Drawing::Rectangle(this->leftTextBox->Left, this->leftTextBox->Top, this->leftTextBox->Width, this->leftTextBox->Height);

			// rightTextBox
			this->rightTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->rightTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rightTextBox->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
			this->rightTextBox->ForeColor = System::Drawing::SystemColors::Window;
			this->rightTextBox->Name = L"rightTextBox1";

			this->rightTextBox->Size = System::Drawing::Size(this->panelTextBox->Width * 45 / 100, this->panelTextBox->Height * 90 / 100);
			this->rightTextBox->Location = System::Drawing::Point(this->panelTextBox->Width - this->rightTextBox->Width, this->panelTextBox->Height * 5 / 100);
			this->rightTextBox->TabIndex = 6;
			this->rightTextBoxTextBox = System::Drawing::Rectangle(this->rightTextBox->Left, this->rightTextBox->Top, this->rightTextBox->Width, this->rightTextBox->Height);

			// panelRedDarck
			this->panelRedDarck->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->panelRedDarck->Name = L"panelRedDarck1";
			this->panelRedDarck->TabStop = false;
			this->panelRedDarck->Location = System::Drawing::Point(this->panelTextBox->Width * 5 / 10 - this->panelTextBox->Width * 5 / 100, 0);
			this->panelRedDarck->Size = System::Drawing::Size(this->panelTextBox->Width * 10 / 100, panelTextBox->Height);
			this->panelRedDarckPanel = System::Drawing::Rectangle(this->panelRedDarck->Left, this->panelRedDarck->Top, this->panelRedDarck->Width, this->panelRedDarck->Height);

			//AddZone
			this->panelTextBox->Controls->Add(this->leftTextBox);
			this->panelTextBox->Controls->Add(this->panelRedDarck);
			this->panelTextBox->Controls->Add(this->rightTextBox);

			this->backgroundInputZone->Controls->Add(this->bannerLightGrey);
			this->backgroundInputZone->Controls->Add(this->panelTextBox);

			this->Menu->Controls->Add(this->scrollBar);
			this->Menu->Controls->Add(this->startCard);
			this->Menu->Controls->Add(this->startLearn);
			this->Menu->Controls->Add(this->startWrite);
			this->Menu->Controls->Add(this->StartPlusTard);
			this->Menu->Controls->Add(this->backgroundInputZone);
			this->Menu->Controls->Add(this->backgroundMask);

			// MainPage
			this->Controls->Add(this->handle);
			this->Controls->Add(this->scrollBar);
			this->Controls->Add(this->Menu);
			this->Name = L"MainPage";
			this->Text = L"QzCPP";
			this->Resize += gcnew System::EventHandler(this, &MainPage::MainPage_Resize);
			this->Menu->ResumeLayout(false);
			this->ResumeLayout(false);
		}
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>

		/*
		void InitializeComponent(void)
		{
			
			
			
			this->rightPP1 = (gcnew System::Windows::Forms::Panel());
			this->rightTB1 = (gcnew System::Windows::Forms::TextBox());
			this->leftPP1 = (gcnew System::Windows::Forms::Panel());
			this->leftTB1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());

			this->Learn = (gcnew System::Windows::Forms::Panel());
			this->backgroundDG->SuspendLayout();
			this->panelTB1->SuspendLayout();
			this->rightPP1->SuspendLayout();
			this->leftPP1->SuspendLayout();
			this->Menu->SuspendLayout();
			this->SuspendLayout();
			//
			// backgroundDG
			//
			this->backgroundDG->AutoScroll = true;
			this->backgroundDG->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->backgroundDG->Controls->Add(this->panelTB1);
			this->backgroundDG->Controls->Add(this->bannerLG);
			this->backgroundDG->Controls->Add(this->button2);
			this->backgroundDG->Controls->Add(this->button1);
			this->backgroundDG->Location = System::Drawing::Point(0, 196);
			this->backgroundDG->Margin = System::Windows::Forms::Padding(0);
			this->backgroundDG->Name = L"backgroundDG";
			this->backgroundDG->Size = System::Drawing::Size(1584, 665);
			this->backgroundDG->TabIndex = 2;
			//
			// panelTB1
			//
			this->panelTB1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panelTB1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->panelTB1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTB1->Controls->Add(this->panelRD1);
			this->panelTB1->Controls->Add(this->rightPP1);
			this->panelTB1->Controls->Add(this->leftPP1);
			this->panelTB1->Location = System::Drawing::Point(240, 258);
			this->panelTB1->Name = L"panelTB1";
			this->panelTB1->Size = System::Drawing::Size(1120, 52);
			this->panelTB1->TabIndex = 1;
			this->panelTB1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainPage::panel4_Paint);
			//
			// panelRD1
			//
			this->panelRD1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->panelRD1->Location = System::Drawing::Point(557, 6);
			this->panelRD1->Margin = System::Windows::Forms::Padding(0);
			this->panelRD1->Name = L"panelRD1";
			this->panelRD1->Size = System::Drawing::Size(6, 40);
			this->panelRD1->TabIndex = 3;
			//
			// rightPP1
			//
			this->rightPP1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->rightPP1->Controls->Add(this->rightTB1);
			this->rightPP1->Location = System::Drawing::Point(563, 0);
			this->rightPP1->Margin = System::Windows::Forms::Padding(0);
			this->rightPP1->Name = L"rightPP1";
			this->rightPP1->Size = System::Drawing::Size(557, 50);
			this->rightPP1->TabIndex = 2;
			//
			// rightTB1
			//
			this->rightTB1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->rightTB1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->rightTB1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rightTB1->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->rightTB1->ForeColor = System::Drawing::SystemColors::Window;
			this->rightTB1->Location = System::Drawing::Point(10, 9);
			this->rightTB1->Margin = System::Windows::Forms::Padding(0);
			this->rightTB1->Name = L"rightTB1";
			this->rightTB1->Size = System::Drawing::Size(537, 32);
			this->rightTB1->TabIndex = 0;
			//
			// leftPP1
			//
			this->leftPP1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->leftPP1->Controls->Add(this->leftTB1);
			this->leftPP1->Location = System::Drawing::Point(0, 0);
			this->leftPP1->Margin = System::Windows::Forms::Padding(0);
			this->leftPP1->Name = L"leftPP1";
			this->leftPP1->Size = System::Drawing::Size(557, 50);
			this->leftPP1->TabIndex = 1;
			//
			// leftTB1
			//
			this->leftTB1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->leftTB1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->leftTB1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->leftTB1->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->leftTB1->ForeColor = System::Drawing::SystemColors::Window;
			this->leftTB1->Location = System::Drawing::Point(10, 9);
			this->leftTB1->Margin = System::Windows::Forms::Padding(0);
			this->leftTB1->Name = L"leftTB1";
			this->leftTB1->Size = System::Drawing::Size(537, 32);
			this->leftTB1->TabIndex = 0;
			this->leftTB1->TextChanged += gcnew System::EventHandler(this, &MainPage::leftTB1_TextChanged);
			//
			// bannerLG
			//
			this->bannerLG->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->bannerLG->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->bannerLG->Location = System::Drawing::Point(0, 16);
			this->bannerLG->Margin = System::Windows::Forms::Padding(0);
			this->bannerLG->Name = L"bannerLG";
			this->bannerLG->Size = System::Drawing::Size(1600, 50);
			this->bannerLG->TabIndex = 0;
			//
			// button2
			//
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->button2->Location = System::Drawing::Point(1394, 195);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 78);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Test";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainPage::Test);
			//
			// button1
			//
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->button1->Location = System::Drawing::Point(1394, 111);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 78);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainPage::AddRow);
			//
			// Learn
			//
			this->Learn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Learn->Location = System::Drawing::Point(0, 0);
			this->Learn->Name = L"Learn";
			this->Learn->Size = System::Drawing::Size(1743, 1077);
			this->Learn->TabIndex = 8;
			this->Learn->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainPage::Learn_Paint);
			//

		}
			*/

#pragma endregion
/*
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
	private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	*/
	private: System::Void MainPage_Resize(System::Object^ sender, System::EventArgs^ e) {
		ResizeAll();
	}

	public: System::Void ResizeAll();
};
}
