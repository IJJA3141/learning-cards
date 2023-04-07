#include <fstream>
#include <vector>
#include <string>
#include "readAndWrite.h"

void readFile(const char* _fileName, std::vector<std::vector<std::string>>* _strVector)
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
            if (line % 2) {
                buffer = str;
            }
            else
            {
                _strVector->push_back({ buffer, str });
            }
        }

        file.close();
    }

    return;
}

void writeFile(const char* _fileName, std::vector<std::vector<std::string>>* _strVector)
{
    std::fstream file;
    file.open(_fileName, std::ios::out);

    if (file.is_open()) {
        for (int i = 0; i < _strVector->size(); i++)
        {
            file << _strVector->at(i)[0] << "\n" << _strVector->at(i)[1] << "\n";
        }

        file.close();
    }

    return;
}
