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

#include <algorithm>
#include <random>

using namespace System::Windows::Forms;
using namespace System;
using namespace std;

wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

string fromSystemstringToString(String^ text)
{
    return converter.to_bytes(msclr::interop::marshal_as<std::wstring>(text));
}
String^ fromStringToSystemstring(string text)
{
    return gcnew String(converter.from_bytes(text).c_str());
}

void store(string fileName, vector<vector<string>> vocList)
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
    if (vocList.size() == 0)
    {
        vocList.resize(vocList.size() + 1, { "", "" });
    }
    return vocList;
}
vector<vector<string>> vocList = createVocList("vocList.txt", " ");

System::Void QzCPP::MainPage::Populate()
{
    pos += posIncr;

    this->leftTB1->Text = fromStringToSystemstring(vocList[0][0]);
    this->rightTB1->Text = fromStringToSystemstring(vocList[0][1]);

    for (int i = 1; i < vocList.size(); i++)
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
        panelRDx->Name = L"panelRD" + (i + 1);

        rightTBx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
        rightTBx->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
        rightTBx->BorderStyle = System::Windows::Forms::BorderStyle::None;
        rightTBx->Anchor = System::Windows::Forms::AnchorStyles::None;
        rightTBx->ForeColor = System::Drawing::SystemColors::Window;
        rightTBx->Margin = System::Windows::Forms::Padding(0);
        rightTBx->Location = System::Drawing::Point(10, 9);
        rightTBx->Size = System::Drawing::Size(537, 32);
        rightTBx->TabIndex = 0;
        rightTBx->Name = L"rightTB" + (i + 1);

        rightTBx->Text = fromStringToSystemstring(vocList[i][1]);

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
        leftTBx->Name = L"leftTB" + (i + 1);

        leftTBx->Text = fromStringToSystemstring(vocList[i][0]);

        rightPPx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
        rightPPx->Margin = System::Windows::Forms::Padding(0);
        rightPPx->Location = System::Drawing::Point(563, 0);
        rightPPx->Size = System::Drawing::Size(557, 50);
        rightPPx->TabIndex = 2;
        rightPPx->Controls->Add(rightTBx);
        rightPPx->Name = L"rightPP" + (i + 1);

        leftPPx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
        leftPPx->Margin = System::Windows::Forms::Padding(0);
        leftPPx->Location = System::Drawing::Point(0, 0);
        leftPPx->Size = System::Drawing::Size(557, 50);
        leftPPx->TabIndex = 1;
        leftPPx->Controls->Add(leftTBx);
        leftPPx->Name = L"leftPP" + (i + 1);

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
        panelTBx->Name = L"panelTB" + (i + 1);

        this->ClientSize = System::Drawing::Size(1584, 665 + (i * (50 + posIncr)));
        this->backgroundDG->Size = System::Drawing::Size(1584, 665 + (i * (50 + posIncr)));
        this->backgroundDG->Controls->Add(panelTBx);
        pos += posIncr;

        NumberOfLine += 1;
    }
}

System::Void QzCPP::MainPage::AddRow(System::Object^ sender, System::EventArgs^ e)
{
    pos += posIncr;

    NumberOfLine += 1;

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
    panelRDx->Name = L"panelRD" + (NumberOfLine);

    rightTBx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
    rightTBx->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
    rightTBx->BorderStyle = System::Windows::Forms::BorderStyle::None;
    rightTBx->Anchor = System::Windows::Forms::AnchorStyles::None;
    rightTBx->ForeColor = System::Drawing::SystemColors::Window;
    rightTBx->Margin = System::Windows::Forms::Padding(0);
    rightTBx->Location = System::Drawing::Point(10, 9);
    rightTBx->Size = System::Drawing::Size(537, 32);
    rightTBx->TabIndex = 0;
    rightTBx->Name = L"rightTB" + (NumberOfLine);

    leftTBx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
    leftTBx->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
    leftTBx->BorderStyle = System::Windows::Forms::BorderStyle::None;
    leftTBx->Anchor = System::Windows::Forms::AnchorStyles::None;
    leftTBx->ForeColor = System::Drawing::SystemColors::Window;
    leftTBx->Margin = System::Windows::Forms::Padding(0);
    leftTBx->Location = System::Drawing::Point(10, 9);
    leftTBx->Size = System::Drawing::Size(537, 32);
    leftTBx->TabIndex = 0;
    leftTBx->Name = L"leftTB" + (NumberOfLine);

    rightPPx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
    rightPPx->Margin = System::Windows::Forms::Padding(0);
    rightPPx->Location = System::Drawing::Point(563, 0);
    rightPPx->Size = System::Drawing::Size(557, 50);
    rightPPx->TabIndex = 2;
    rightPPx->Controls->Add(rightTBx);
    rightPPx->Name = L"rightPP" + (NumberOfLine);

    leftPPx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
    leftPPx->Margin = System::Windows::Forms::Padding(0);
    leftPPx->Location = System::Drawing::Point(0, 0);
    leftPPx->Size = System::Drawing::Size(557, 50);
    leftPPx->TabIndex = 1;
    leftPPx->Controls->Add(leftTBx);
    leftPPx->Name = L"leftPP" + (NumberOfLine);

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
    panelTBx->Name = L"panelTB" + (NumberOfLine);

    this->ClientSize = System::Drawing::Size(1584, 665 + (NumberOfLine * (50 + posIncr)));
    this->backgroundDG->Size = System::Drawing::Size(1584, 665 + (NumberOfLine * (50 + posIncr)));
    this->backgroundDG->Controls->Add(panelTBx);
    pos += posIncr;

    vocList.resize(vocList.size() + 1, { "", "" });

    return System::Void();
}

bool emptyOrNot(System::String^ sstr)
{
    return System::String::IsNullOrWhiteSpace(sstr);
}

System::Void QzCPP::MainPage::UpDateVocList()
{
    int backgroundDGPath;
    int StoringPosition;
    int firstPanel;
    int antJ = 1;

    if (emptyOrNot(this->leftTB1->Text) && emptyOrNot(this->rightTB1->Text)) {
        vocList.erase(vocList.begin());
        antJ--;
    }
    else {
        vocList[0][0] = fromSystemstringToString(this->leftTB1->Text);
        vocList[0][1] = fromSystemstringToString(this->rightTB1->Text);
    }

    for (int i = 0; i < this->Controls->Count; i++)
    {
        if (this->Menu->Controls[i]->Name == L"backgroundDG")
        {
            backgroundDGPath = i;
            break;
        }
    }

    for (int i = 0; i < this->Menu->Controls[backgroundDGPath]->Controls->Count; i++)
    {
        if (this->Menu->Controls[backgroundDGPath]->Controls[i]->Name == L"panelTB2")
        {
            firstPanel = i;
            break;
        }
    }

    for (int i = firstPanel, j = antJ; i < NumberOfLine + firstPanel - 1 && j <= vocList.size(); i++, j++)
    {
        if (emptyOrNot(this->Menu->Controls[backgroundDGPath]->Controls[i]->Controls[2]->Controls[0]->Text) && emptyOrNot(this->Menu->Controls[backgroundDGPath]->Controls[i]->Controls[1]->Controls[0]->Text)) {
            vocList.erase(vocList.begin() + j);
            j--;
        }
        else {
            vocList[j][0] = fromSystemstringToString(this->Menu->Controls[backgroundDGPath]->Controls[i]->Controls[2]->Controls[0]->Text);
            vocList[j][1] = fromSystemstringToString(this->Menu->Controls[backgroundDGPath]->Controls[i]->Controls[1]->Controls[0]->Text);
        }
        StoringPosition = i;
    }

    store("vocList.txt", vocList);
}

System::Void QzCPP::MainPage::OnFormClosing(System::Object^ sender, System::EventArgs^ e)
{
    UpDateVocList();
    return System::Void();
}

System::Void QzCPP::MainPage::TestD(System::Object^ sender, System::EventArgs^ e)
{
    for (int i = 0; i < this->Learn->Controls->Count; i++)
    {
        delete this->Learn->Controls[i];
    }
    this->Learn->Hide();
    this->Menu->Show();
}
System::Void QzCPP::MainPage::Test(System::Object^ sender, System::EventArgs^ e)
{
    UpDateVocList();
    NewCard();
    this->Menu->Hide();
    this->Learn->Show();
}

System::Void QzCPP::MainPage::NewCard()
{
    int Fw = this->Width * 30 / 100;
    int Fh = this->Height * 3 / 6;

    int numVoc = 10;
    if (numVoc > vocList.size()) { numVoc = vocList.size(); }
    vector<int> arr;
    for (int i = 0; i < numVoc; i++)
    {
        arr.push_back(i);
    }

    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(arr), std::end(arr), rng);

    System::Windows::Forms::Panel^ Frame = gcnew System::Windows::Forms::Panel();

    System::Windows::Forms::Label^ Term = gcnew System::Windows::Forms::Label();
    System::Windows::Forms::Label^ VocPos = gcnew System::Windows::Forms::Label();

    System::Windows::Forms::TextBox^ Ans = gcnew System::Windows::Forms::TextBox();

    System::Windows::Forms::Button^ Help = gcnew System::Windows::Forms::Button();
    System::Windows::Forms::Button^ Ret = gcnew System::Windows::Forms::Button();
    System::Windows::Forms::Button^ BackMenu = gcnew System::Windows::Forms::Button();

    Frame->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
    Frame->Location = System::Drawing::Point(7*this->Width/20, this->Height/6);
    Frame->Size = System::Drawing::Size(Fw, Fh);

    Term->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 20.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    Term->ForeColor = System::Drawing::SystemColors::Window;

    Term->Text = fromStringToSystemstring(vocList[arr[0]][0]);

    Term->Location = System::Drawing::Point(0, Fh/10);
    Term->Size = System::Drawing::Size(Fw, 100);
    Term->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    
    VocPos->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    VocPos->ForeColor = System::Drawing::SystemColors::Window;
    VocPos->Location = System::Drawing::Point(Fw*90/100, 3);
    VocPos->Size = System::Drawing::Size(Fw*10/100, 100);
    VocPos->Text = L"1/10";

    Ans->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
    Ans->BorderStyle = System::Windows::Forms::BorderStyle::None;
    Ans->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
    Ans->ForeColor = System::Drawing::SystemColors::Window;
    Ans->Margin = System::Windows::Forms::Padding(0);
    Ans->Location = System::Drawing::Point(Fw/20, Fh-100);
    Ans->Size = System::Drawing::Size(Fw*18/20, 40);

    Help->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
    Help->Location = System::Drawing::Point(100, Fh-50);
    Help->Size = System::Drawing::Size(100, 50);

    Ret->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
    Ret->Location = System::Drawing::Point(300, Fh-50);
    Ret->Size = System::Drawing::Size(100, 50);

    BackMenu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
    BackMenu->Location = System::Drawing::Point(0, 0);
    BackMenu->Size = System::Drawing::Size(100, 50);
    BackMenu->Click += gcnew System::EventHandler(this, &MainPage::TestD);

    Frame->Controls->Add(Term);
    Frame->Controls->Add(VocPos);
    Frame->Controls->Add(Ans);
    Frame->Controls->Add(Help);
    Frame->Controls->Add(Ret);
    Frame->Controls->Add(BackMenu);
    
    this->Learn->Controls->Add(Frame);
}

[STAThread]

void main() {
    System::Windows::Forms::Application::EnableVisualStyles();
    QzCPP::MainPage form;
    Application::Run(% form);
}