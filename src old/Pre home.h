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
	class HomePage
	{
	private:
		HomePage(qz::Screen** _ppScreen);
		static HomePage* m_pHomePage;
		
		std::vector<std::string> m_list;
		int m_listPos;

		ftxui::Component m_lists;
		ftxui::Component m_buttons;
		ftxui::Component m_comp;
		
		qz::DeletePage* m_pDeletePage;
		qz::AddPage* m_pAddPage;
		qz::Raw* m_pRaw;

	public:
		static HomePage* homePage(qz::Screen** _ppScreen);

		ftxui::Component component;

		HomePage(HomePage& other) = delete;
		void operator = (const HomePage&) = delete;
	};
};


#endif // !QZHOMEPAGE
