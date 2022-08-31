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

using namespace System::Windows::Forms;
using namespace System;
using namespace std;

namespace test {
    wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    public class MyClass
    {
    public:
        static vector<vector<string>> createVocList(string fileName, string spliter)
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
        
        static void store(string fileName, vector<vector<string>> vocList)
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
        
        static string fromSystemstringToString(String^ text)
        {
            return converter.to_bytes(msclr::interop::marshal_as<std::wstring>(text));
        }

        static String^ fromStringToSystemstring(string text)
        {
            return gcnew String(converter.from_bytes(text).c_str());
        }

        static bool emptyOrNot(System::String^ sstr)
        {
            return System::String::IsNullOrWhiteSpace(sstr);
        }

        static vector<vector<string>> vocList;

        static int NumberOfLine;
        static int posIncr;
        static int pos;
    };
}

using namespace test;

int MyClass::NumberOfLine = 1;
int MyClass::pos = 258;
int MyClass::posIncr = 200;

vector<vector<string>> MyClass::vocList = createVocList("vocList.txt", " ");

System::Void QzCPP::MainPage::OnFormClosing(System::Object^ sender, System::EventArgs^ e)
{
    int backgroundDGPath;
    int StoringPosition;
    int firstPanel;
    int antJ = 1;

    if (MyClass::emptyOrNot(this->leftTB1->Text) && MyClass::emptyOrNot(this->rightTB1->Text)) {
        MyClass::vocList.erase(MyClass::vocList.begin());
        antJ--;
    }
    else {
        MyClass::vocList[0][0] = MyClass::fromSystemstringToString(this->leftTB1->Text);
        MyClass::vocList[0][1] = MyClass::fromSystemstringToString(this->rightTB1->Text);
    }

    for (int i = 0; i < this->Controls->Count; i++)
    {
        if (this->Controls[i]->Name == L"backgroundDG")
        {
            backgroundDGPath = i;
            break;
        }
    }

    for (int i = 0; i < this->Controls[backgroundDGPath]->Controls->Count; i++)
    {
        if (this->Controls[backgroundDGPath]->Controls[i]->Name == L"panelTB2")
        {
            firstPanel = i;
            break;
        }
    }

    for (int i = firstPanel, j = antJ; i < MyClass::NumberOfLine + firstPanel - 1 && j <= MyClass::vocList.size(); i++, j++)
    {
        if (MyClass::emptyOrNot(this->Controls[backgroundDGPath]->Controls[i]->Controls[2]->Controls[0]->Text) && MyClass::emptyOrNot(this->Controls[backgroundDGPath]->Controls[i]->Controls[1]->Controls[0]->Text)) {
            MyClass::vocList.erase(MyClass::vocList.begin() + j);
            j--;
        }
        else {
            MyClass::vocList[j][0] = MyClass::fromSystemstringToString(this->Controls[backgroundDGPath]->Controls[i]->Controls[2]->Controls[0]->Text);
            MyClass::vocList[j][1] = MyClass::fromSystemstringToString(this->Controls[backgroundDGPath]->Controls[i]->Controls[1]->Controls[0]->Text);
        }
        StoringPosition = i;
    }

    MyClass::store("vocList.txt", MyClass::vocList);

    return System::Void();
}

System::Void QzCPP::MainPage::AddRow(System::Object^ sender, System::EventArgs^ e)
{
    MyClass::pos += MyClass::posIncr;

    MyClass::NumberOfLine += 1;

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
    panelRDx->Name = L"panelRD" + (MyClass::NumberOfLine);

    rightTBx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
    rightTBx->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
    rightTBx->BorderStyle = System::Windows::Forms::BorderStyle::None;
    rightTBx->Anchor = System::Windows::Forms::AnchorStyles::None;
    rightTBx->ForeColor = System::Drawing::SystemColors::Window;
    rightTBx->Margin = System::Windows::Forms::Padding(0);
    rightTBx->Location = System::Drawing::Point(10, 9);
    rightTBx->Size = System::Drawing::Size(537, 32);
    rightTBx->TabIndex = 0;
    rightTBx->Name = L"rightTB" + (MyClass::NumberOfLine);

    leftTBx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
    leftTBx->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
    leftTBx->BorderStyle = System::Windows::Forms::BorderStyle::None;
    leftTBx->Anchor = System::Windows::Forms::AnchorStyles::None;
    leftTBx->ForeColor = System::Drawing::SystemColors::Window;
    leftTBx->Margin = System::Windows::Forms::Padding(0);
    leftTBx->Location = System::Drawing::Point(10, 9);
    leftTBx->Size = System::Drawing::Size(537, 32);
    leftTBx->TabIndex = 0;
    leftTBx->Name = L"leftTB" + (MyClass::NumberOfLine);

    rightPPx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
    rightPPx->Margin = System::Windows::Forms::Padding(0);
    rightPPx->Location = System::Drawing::Point(563, 0);
    rightPPx->Size = System::Drawing::Size(557, 50);
    rightPPx->TabIndex = 2;
    rightPPx->Controls->Add(rightTBx);
    rightPPx->Name = L"rightPP" + (MyClass::NumberOfLine);

    leftPPx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
    leftPPx->Margin = System::Windows::Forms::Padding(0);
    leftPPx->Location = System::Drawing::Point(0, 0);
    leftPPx->Size = System::Drawing::Size(557, 50);
    leftPPx->TabIndex = 1;
    leftPPx->Controls->Add(leftTBx);
    leftPPx->Name = L"leftPP" + (MyClass::NumberOfLine);

    panelTBx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
    panelTBx->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainPage::panel4_Paint);
    panelTBx->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    panelTBx->Anchor = System::Windows::Forms::AnchorStyles::None;
    panelTBx->Size = System::Drawing::Size(1120, 52);
    panelTBx->TabIndex = 1;
    panelTBx->Location = System::Drawing::Point(240, MyClass::pos);
    panelTBx->Controls->Add(panelRDx);
    panelTBx->Controls->Add(rightPPx);
    panelTBx->Controls->Add(leftPPx);
    panelTBx->Name = L"panelTB" + (MyClass::NumberOfLine);

    this->ClientSize = System::Drawing::Size(1584, 665 + (MyClass::NumberOfLine * (50 + MyClass::posIncr)));
    this->backgroundDG->Size = System::Drawing::Size(1584, 665 + (MyClass::NumberOfLine * (50 + MyClass::posIncr)));
    this->backgroundDG->Controls->Add(panelTBx);
    MyClass::pos += MyClass::posIncr;

    MyClass::vocList.resize(MyClass::vocList.size() + 1, { "", "" });

    return System::Void();
}

System::Void QzCPP::MainPage::Test(System::Object^ sender, System::EventArgs^ e)
{
    //fromSystemstringToString
    // 
    //fromStringToSystemstring
    //Test
}

System::Void QzCPP::MainPage::Populate()
{
    MyClass::pos += MyClass::posIncr;

    this->leftTB1->Text = MyClass::fromStringToSystemstring(MyClass::vocList[0][0]);
    this->rightTB1->Text = MyClass::fromStringToSystemstring(MyClass::vocList[0][1]);

    for (int i = 1; i < MyClass::vocList.size(); i++)
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

        rightTBx->Text = MyClass::fromStringToSystemstring(MyClass::vocList[i][1]);


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


        leftTBx->Text = MyClass::fromStringToSystemstring(MyClass::vocList[i][0]);


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
        panelTBx->Location = System::Drawing::Point(240, MyClass::pos);
        panelTBx->Controls->Add(panelRDx);
        panelTBx->Controls->Add(rightPPx);
        panelTBx->Controls->Add(leftPPx);
        panelTBx->Name = L"panelTB" + (i + 1);

        this->ClientSize = System::Drawing::Size(1584, 665 + (i * (50 + MyClass::posIncr)));
        this->backgroundDG->Size = System::Drawing::Size(1584, 665 + (i * (50 + MyClass::posIncr)));
        this->backgroundDG->Controls->Add(panelTBx);
        MyClass::pos += MyClass::posIncr;

        MyClass::NumberOfLine += 1;
    }
}

[STAThread]

void main() {
    System::Windows::Forms::Application::EnableVisualStyles();
    QzCPP::MainPage form;
    Application::Run(% form);
}