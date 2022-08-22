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

System::Void QzCPP::MainPage::populate(System::Object^ sender, System::EventArgs^ e)
{
    /*
    store("vocList.txt", converter.to_bytes(msclr::interop::marshal_as<std::wstring>(leftTB1->Text)));
    rightTB1->Text = gcnew String(converter.from_bytes(getFile("vocList.txt", " ")).c_str());
    */

    return System::Void();
}

vector<vector<string>> vocList = createVocList("vocList.txt", " ");

void main() {
    System::Windows::Forms::Application::EnableVisualStyles();
    QzCPP::MainPage form;
    Application::Run(% form);
}
