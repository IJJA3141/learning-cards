#pragma once

#ifndef ReadAndWrite
#define ReadAndWrite

#include <string>
#include <vector>

#define _PATH_CONTENT "./.appcache/content/"
#define _PATH_LISTS "./.appcache/lists/.txt"

void getListContent(const char* _fileName, std::vector<std::vector<std::string>>* _pStrVectVector);
void setListContent(const char* _fileName, std::vector<std::vector<std::string>>* _pStrVectVector);

void getLists(const char* _fileName, std::vector<std::string>* _pStrVector);
void setLists(const char* _fileName, std::vector<std::string>* _pStrVector);

void deleteList(std::string _fileName);

#endif // RAW