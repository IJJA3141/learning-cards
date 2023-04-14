#include <fstream>
#include <vector>
#include <string>
#include "readAndWrite.h"

#include <iostream>

void getListContent(const char* _fileName, std::vector<std::vector<std::string>>* _pStrVectVector)
{
    std::fstream file;
    file.open(_fileName, std::ios::in);

    if (file.is_open())
    {
        int line = 0;
        std::string str;
        std::string buffer;

        while (std::getline(file, str))
        {
            line++;
            if (line % 2)
            {
                buffer = str;
            }
            else
            {
                _pStrVectVector->push_back({ buffer, str });
            }
        }

        file.close();
    }

    return;
}

void setListContent(const char* _fileName, std::vector<std::vector<std::string>>* _pStrVectVector)
{
    std::fstream file;
    file.open(_fileName, std::ios::out);

    if (file.is_open()) 
    {
        for (int i = 0; i < _pStrVectVector->size(); i++)
        {
            file << _pStrVectVector->at(i)[0] << "\n" << _pStrVectVector->at(i)[1] << "\n";
        }

        file.close();
    }

    return;
}

void getLists(const char* _fileName, std::vector<std::string>* _pStrVector)
{
    std::fstream file;
    file.open(_fileName, std::ios::in);

    if (file.is_open())
    {
        std::string str;

        while (std::getline(file, str))
        {
            _pStrVector->push_back(str);
        }

        file.close();
    }

    return;
}

void setLists(const char* _fileName, std::vector<std::string>* _pStrVector)
{
    std::fstream file;
    file.open(_fileName, std::ios::out);

    if (file.is_open()) 
    {
        std::string str;
        for (int i = 0; i < _pStrVector->size(); i++)
        {
            file << _pStrVector->at(i) << "\n";
        }
    }

    return;
}

void deleteList(const char* _fileName)
{
    char buffer[sizeof(_PATH_CONTENT) + sizeof(_fileName) + sizeof(".txt")];

    strcpy(buffer, _PATH_CONTENT);
    strcat(buffer, _fileName);
    strcat(buffer, ".txt");

    const char* file = buffer;

    std::remove(buffer);

    return;
}
