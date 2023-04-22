#pragma once

#ifndef ReadAndWrite
#define ReadAndWrite

#include <string>
#include <vector>

#define _PATH_CONTENT "./.appcache/content/"
#define _PATH_LISTS "./.appcache/lists/.txt"

namespace qz
{
	class Raw
	{
	private:
		Raw(std::vector<std::string>* _pStrVector);

		static qz::Raw* m_pRaw;

		std::vector<std::string>* m_pStrVector;

	public:
		static qz::Raw* raw(std::vector<std::string>* _pStrVector);

		Raw(Raw& other) = delete;
		void operator = (const Raw&) = delete;

		void getLists();
		void setLists();

		void getListContent(const char* _fileName, std::vector<std::vector<std::string>>* _pStrVectVector);
		void setListContent(const char* _fileName, std::vector<std::vector<std::string>>* _pStrVectVector);
		
		void deleteList(int _vectorIndex);
	};
}

#endif // RAW