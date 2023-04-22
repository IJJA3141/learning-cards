#include <fstream>
#include <vector>
#include <string>
#include "readAndWrite.h"

#include <iostream>

qz::Raw* qz::Raw::m_pRaw = nullptr;

qz::Raw::Raw(std::vector<std::string>* _pStrVector)
{
    this->m_pStrVector = _pStrVector;
};

qz::Raw* qz::Raw::raw(std::vector<std::string>* _pStrVector)
{
    if (qz::Raw::m_pRaw == nullptr && _pStrVector == nullptr) throw std::invalid_argument("Raw need to be initialized with a pointer to a vector !");
    if (qz::Raw::m_pRaw == nullptr)
    {
        qz::Raw::m_pRaw = new qz::Raw(_pStrVector);
    }

    return qz::Raw::m_pRaw;
};

void qz::Raw::getLists()
{
    this->m_pStrVector->clear();

    std::fstream file;
    file.open(_PATH_LISTS, std::ios::in);

    if (file.is_open())
    {
        std::string str;

        while (std::getline(file, str))
        {
            this->m_pStrVector->push_back(str);
        }

        file.close();
    }

    return;
};

void qz::Raw::setLists()
{
    std::fstream file;
    file.open(_PATH_LISTS, std::ios::out);

    if (file.is_open())
    {
        std::string str;
        for (int i = 0; i < this->m_pStrVector->size(); i++)
        {
            file << this->m_pStrVector->at(i) << "\n";
        }
    }

    return;
};


void qz::Raw::deleteList(int _vectorIndex)
{
    char buffer[sizeof(_PATH_CONTENT) + sizeof(this->m_pStrVector->at(_vectorIndex)) + sizeof(".txt")];

    strcpy_s(buffer, _PATH_CONTENT);
    strcat_s(buffer, this->m_pStrVector->at(_vectorIndex).c_str());
    strcat_s(buffer, ".txt");

    this->m_pStrVector->erase(this->m_pStrVector->begin() + _vectorIndex);

    std::remove(buffer);

    this->setLists();

    return;
}


void qz::Raw::getListContent(const char* _fileName, std::vector<std::vector<std::string>>* _pStrVectVector)
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

void qz::Raw::setListContent(const char* _fileName, std::vector<std::vector<std::string>>* _pStrVectVector)
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