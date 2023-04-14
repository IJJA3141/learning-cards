#pragma once

#ifndef QZHOMEPAGE
#define QZHOMEPAGE

#include "readAndWrite.h"

#include "ftxui/component/component.hpp"

#include <vector>
#include <string>

#include "screen.h"
#include "delete.h"

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

	public:
		static HomePage* homePage(qz::Screen** _ppScreen);

		qz::DeletePage* pDeletePage;
		ftxui::Component component;

		HomePage(HomePage& other) = delete;
		void operator = (const HomePage&) = delete;
	};
};


#endif // !QZHOMEPAGE
