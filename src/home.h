#pragma once

#ifndef QZHOMEPAGE
#define QZHOMEPAGE

#include "ftxui/component/component.hpp"

#include <vector>
#include <string>

#include "readAndWrite.h"
#include "screen.h"
#include "delete.h"
#include "add.h"

namespace qz
{
	class sHomePage
	{
	private:
		sHomePage();

		static sHomePage* m_pSHomePage;
		
		ftxui::Component m_buttons;
		ftxui::Component m_lists;
		ftxui::Component m_comp;

		qz::DeletePage* m_pDeletePage;
		qz::AddPage* m_pAddPage;
		qz::sScreen* m_pScreen;
		qz::Raw* m_pRaw;

	public:
		static sHomePage* get();

		ftxui::Component component;

		std::vector<std::string> lists;
		int index;

		sHomePage(sHomePage& other) = delete;
		void operator = (const sHomePage&) = delete;
	};
};


#endif // !QZHOMEPAGE
