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
[STAThread]

string fromSystemstringToString(String^ text)
{
    return msclr::interop::marshal_as<std::string>(text);
}

wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

String^ fromStringToSystemstring(string text)
{
    return msclr::interop::marshal_as<System::String^>(text);
}

string getFile(string fileName, string spliter) {
    fstream file;
    string localeVocList;
    file.open(fileName, ios::in);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            localeVocList = line;
        }
        file.close();
    }

    return localeVocList;
}

void store(string fileName, string text)
{
    fstream file;
    file.open(fileName, ios::out);
    if (file.is_open())
    {
        file << text;
        file.close();
    }
}

System::Void QzCPP::MainPage::populate(System::Object^ sender, System::EventArgs^ e)
{
    store("vocList.txt", converter.to_bytes(msclr::interop::marshal_as<std::wstring>(leftTB1->Text)));
    rightTB1->Text = gcnew String(converter.from_bytes(getFile("vocList.txt", " ")).c_str());

    return System::Void();
}

int main() {
    System::Windows::Forms::Application::EnableVisualStyles();
    QzCPP::MainPage form;
    Application::Run(% form);
}