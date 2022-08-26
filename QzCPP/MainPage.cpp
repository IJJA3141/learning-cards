#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
#include "MainPage.h"
#include <fstream>
#include <codecvt>
#include <codecvt>
#include <cassert>
#include <locale>
#include <string>
#include <vector>


using namespace std;
using namespace System;
using namespace System::Windows::Forms;

wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

string fromSystemstringToString(String^ text)
{
    return msclr::interop::marshal_as<std::string>(text);
}

String^ fromStringToSystemstring(string text)
{
    return msclr::interop::marshal_as<System::String^>(text);
}

void store(string fileName,vector<vector<string>> vocList)
{
    fstream file;
    file.open(fileName, ios::out);
    if (file.is_open())
    {
        for (size_t i = 0; i < vocList.size(); i++)
        {
            file << vocList[i][0] << " " << vocList[i][1] << "\n";
        }
        file.close();
    }
}

vector<vector<string>> createVocList(string fileName, string spliter)
{
    vector<vector<string>> vocList;
    int linePos = 0;
    fstream file;
    string line;

    file.open(fileName, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            vector<string> temp;

            string t = "　";

            if (line.find(t) != string::npos)
            {
                string left = line.substr(0, line.find(t));
                string right = line.substr(line.find(t) + t.length(), line.length());

                temp.push_back(string(left.begin(), left.end()));
                temp.push_back(string(right.begin(), right.end()));
            }
            else
            {
                string left = line.substr(0, line.find(spliter));
                string right = line.substr(line.find(spliter) + spliter.length(), line.length());

                temp.push_back(string(left.begin(), left.end()));
                temp.push_back(string(right.begin(), right.end()));
            }

            vocList.push_back(temp);
            linePos++;
        }
    }

    return vocList;
}
vector<vector<string>> vocList = createVocList("vocList.txt", " ");

System::Void QzCPP::MainPage::Populate()
{
    int pos = 258;
    int posIncr = 200;

    pos += posIncr;

    this->leftTB1->Text = fromStringToSystemstring(vocList[0][0]);
    this->rightTB1->Text = fromStringToSystemstring(vocList[0][1]);

    for (size_t i = 1; i < vocList.size(); i++)
    {
        System::Windows::Forms::Panel^ panelTBx = gcnew System::Windows::Forms::Panel();

        System::Windows::Forms::Panel^ leftPPx = gcnew System::Windows::Forms::Panel();
        System::Windows::Forms::TextBox^ leftTBx = gcnew System::Windows::Forms::TextBox();

        System::Windows::Forms::Panel^ panelRDx = gcnew System::Windows::Forms::Panel();

        System::Windows::Forms::Panel^ rightPPx = gcnew System::Windows::Forms::Panel();
        System::Windows::Forms::TextBox^ rightTBx = gcnew System::Windows::Forms::TextBox();

        panelTBx->SuspendLayout();

        leftPPx->SuspendLayout();
        rightPPx->SuspendLayout();

        panelRDx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
        panelRDx->Margin = System::Windows::Forms::Padding(0);
        panelRDx->Location = System::Drawing::Point(557, 6);
        panelRDx->Size = System::Drawing::Size(6, 40);
        panelRDx->TabIndex = 3;
        panelRDx->Name = L"panelRD"+i+1;

        rightTBx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
        rightTBx->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
        rightTBx->BorderStyle = System::Windows::Forms::BorderStyle::None;
        rightTBx->Anchor = System::Windows::Forms::AnchorStyles::None;
        rightTBx->ForeColor = System::Drawing::SystemColors::Window;
        rightTBx->Margin = System::Windows::Forms::Padding(0);
        rightTBx->Location = System::Drawing::Point(10, 9);
        rightTBx->Size = System::Drawing::Size(537, 32);
        rightTBx->TabIndex = 0;
        rightTBx->Name = L"rightTB"+i+1;

        rightTBx->Text = gcnew String(converter.from_bytes(vocList[i][1]).c_str());

        leftTBx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
        leftTBx->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
        //leftTBx->TextChanged += gcnew System::EventHandler(this, &MainPage::leftTB1_TextChanged);
        leftTBx->BorderStyle = System::Windows::Forms::BorderStyle::None;
        leftTBx->Anchor = System::Windows::Forms::AnchorStyles::None;
        leftTBx->ForeColor = System::Drawing::SystemColors::Window;
        leftTBx->Margin = System::Windows::Forms::Padding(0);
        leftTBx->Location = System::Drawing::Point(10, 9);
        leftTBx->Size = System::Drawing::Size(537, 32);
        leftTBx->TabIndex = 0;
        leftTBx->Name = L"leftTB"+i+1;

        leftTBx->Text = gcnew String(converter.from_bytes(vocList[i][0]).c_str());

        rightPPx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
        rightPPx->Margin = System::Windows::Forms::Padding(0);
        rightPPx->Location = System::Drawing::Point(563, 0);
        rightPPx->Size = System::Drawing::Size(557, 50);
        rightPPx->TabIndex = 2;
        rightPPx->Controls->Add(rightTBx);
        rightPPx->Name = L"rightPP"+i+1;

        leftPPx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
        leftPPx->Margin = System::Windows::Forms::Padding(0);
        leftPPx->Location = System::Drawing::Point(0, 0);
        leftPPx->Size = System::Drawing::Size(557, 50);
        leftPPx->TabIndex = 1;
        leftPPx->Controls->Add(leftTBx);
        leftPPx->Name = L"leftPP"+i+1;

        panelTBx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
        panelTBx->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainPage::panel4_Paint);
        panelTBx->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        panelTBx->Anchor = System::Windows::Forms::AnchorStyles::None;
        panelTBx->Size = System::Drawing::Size(1120, 52);
        panelTBx->TabIndex = 1;
        panelTBx->Location = System::Drawing::Point(240, pos);
        panelTBx->Controls->Add(panelRDx);
        panelTBx->Controls->Add(rightPPx);
        panelTBx->Controls->Add(leftPPx);
        panelTBx->Name = L"panelTB"+i+1;

        this->ClientSize = System::Drawing::Size(1584, 665 + (i * (50 + posIncr)));
        this->backgroundDG->Size = System::Drawing::Size(1584, 665 + (i * (50 + posIncr)));
        this->backgroundDG->Controls->Add(panelTBx);
        pos += posIncr;

        NumberOfLine += 1;
    }
}

System::Void QzCPP::MainPage::AddRow(System::Object^ sender, System::EventArgs^ e)
{
    //-------TEXT------------//
    //                       //
    //ajouter +1 NumberOfLine//
    //                       //
    //-----------------------//


    /*
    store("vocList.txt", converter.to_bytes(msclr::interop::marshal_as<std::wstring>(leftTB1->Text)));
    rightTB1->Text = gcnew String(converter.from_bytes(getFile("vocList.txt", " ")).c_str());
    */   
    
    //this.Controls[name_of_label_to_be_changed].Forecolor = System.Drawing.Color.Red;

    //this->backgroundDG->Controls.Find("textBox1", true).FirstOrDefault()

    //TextBox t = this.Controls.Find("textBox1", true).FirstOrDefault() as TextBox;
    //this->Controls->Count

    int way = 0;
    int backgroundDGPos = 0;

    for (int thisControls = 0; thisControls < this->Controls->Count; thisControls++)
    {
        if (this->Controls[thisControls]->Name == L"backgroundDG")
        {
            backgroundDGPos = thisControls;
        }
    }
    

    for (int i = 0; i < this->Controls[backgroundDGPos]->Controls->Count; i++)
    {
        if (this->Controls[backgroundDGPos]->Controls[i]->Name == L"panelTB2")
        {
            way = i - 1;
            this->leftTB1->Text = fromStringToSystemstring(to_string(way));
            break;
        }
        this->rightTB1->Text = fromStringToSystemstring(this->Controls[backgroundDGPos]->Controls[i]->Name);
    }
    
    this->leftTB1->Text = fromStringToSystemstring(to_string(this->Controls[backgroundDGPos]->Controls->Count));

    vocList[0][0] = fromSystemstringToString(this->leftTB1->Text);
    vocList[0][1] = fromSystemstringToString(this->rightTB1->Text);

    this->leftTB1->Text = fromStringToSystemstring(to_string(way));

    for (int i = 1; i < NumberOfLine - 2; i++)
    {
    /*
    vocList[i][0] = fromSystemstringToString(this->Controls[backgroundDGPos]->Controls[way + i]->Controls[2]->Controls[0]->Text);
    vocList[i][1] = fromSystemstringToString(this->Controls[backgroundDGPos]->Controls[way + i]->Controls[1]->Controls[0]->Text);
    */
    }

    vocList[5][0] = fromSystemstringToString(this->Controls[backgroundDGPos]->Controls[12]->Controls[2]->Controls[0]->Text);
    vocList[5][1] = fromSystemstringToString(this->Controls[backgroundDGPos]->Controls[12]->Controls[1]->Controls[0]->Text);

    /*
    vocList[2][0] = fromSystemstringToString(this->Controls[backgroundDGPos]->Controls[4]->Controls[2]->Controls[0]->Text);
    vocList[2][1] = fromSystemstringToString(this->Controls[backgroundDGPos]->Controls[4]->Controls[1]->Controls[0]->Text);
    */

    /*
    for (int u = 1; u < vocList.size(); u++)
    {
        int q = u - 1;
       
            vocList[u][0] = fromSystemstringToString(this->Controls[way[q][0]]->Controls[way[q][1]]->Controls[2]->Controls[0]->Text);
            vocList[u][1] = fromSystemstringToString(this->Controls[way[q][0]]->Controls[way[q][1]]->Controls[1]->Controls[0]->Text);
    }*/

    //vector<string> tempVec;
    //tempVec.push_back(fromSystemstringToString(this->Controls[way[q][0]]->Controls[way[q][1]]->Controls[2]->Controls[0]->Text));
    //tempVec.push_back(fromSystemstringToString(this->Controls[way[q][0]]->Controls[way[q][1]]->Controls[1]->Controls[0]->Text));
    //vocList.push_back(tempVec);

    store("ext.txt", vocList);

    return System::Void();
}


/*System::Void QzCPP::MainPage::OnFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventHandler^ e)
{
    System::Array^ a;
    this->backgroundDG->Controls->CopyTo(a, 0);
    int test = a->Length;
    this->leftTB1->Text = fromStringToSystemstring(to_string(test));
}*/


[STAThread]

void main() {
    System::Windows::Forms::Application::EnableVisualStyles();
    QzCPP::MainPage form;
    Application::Run(% form);
}

/*
private: ArrayList^ arr = gcnew ArrayList();
        //System::Windows::Forms::TextBox^ textBox10 = gcnew TextBox();

           void test(void)
           {
            System::Windows::Forms::TextBox^ textBox10;
            textBox10 = (gcnew System::Windows::Forms::TextBox());
            SuspendLayout();

            textBox10->Location = System::Drawing::Point(482, 779);
            textBox10->Name = L"textBox1";
            textBox10->Size = System::Drawing::Size(248, 20);
            textBox10->TabIndex = 3;

            arr->Add(textBox10);

            //this->groupBox1->Controls->Add(textBox10);
        }
*/