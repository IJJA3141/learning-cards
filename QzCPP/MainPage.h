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
	public:
		MainPage(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
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
	private: System::Windows::Forms::TextBox^ leftTB1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ rightTB1;
	private: System::Windows::Forms::TextBox^ textBox1;


	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->leftTB1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->rightTB1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// leftTB1
			// 
			this->leftTB1->Location = System::Drawing::Point(32, 141);
			this->leftTB1->Name = L"leftTB1";
			this->leftTB1->Size = System::Drawing::Size(246, 20);
			this->leftTB1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(508, 111);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 78);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainPage::populate);
			// 
			// rightTB1
			// 
			this->rightTB1->Location = System::Drawing::Point(322, 141);
			this->rightTB1->Name = L"rightTB1";
			this->rightTB1->Size = System::Drawing::Size(186, 20);
			this->rightTB1->TabIndex = 2;
			this->rightTB1->TextChanged += gcnew System::EventHandler(this, &MainPage::rightTB1_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(260, 355);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(248, 20);
			this->textBox1->TabIndex = 3;
			// 
			// MainPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(751, 609);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->rightTB1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->leftTB1);
			this->Name = L"MainPage";
			this->Text = L"MainPage";
			this->Load += gcnew System::EventHandler(this, &MainPage::MainPage_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainPage_Load(System::Object^ sender, System::EventArgs^ e) {
	} 
	private: System::Void populate(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rightTB1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
