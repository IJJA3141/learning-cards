#pragma once

#ifndef QZHOMEPAGE
#define QZHOMEPAGE

#include "ftxui/component/component.hpp"

#include <vector>
#include <string>

#include "screen.h"
#include "delete.h"
#include "add.h"

namespace qz
{
	class HomePage
	{
	private:
		HomePage();
		static HomePage* m_pHomePage;
		
		int m_listIndex;
		std::vector<std::string> m_list;

		ftxui::Component m_menu;
		ftxui::Component m_buttons;
		ftxui::Component m_buttonsMenu;

		qz::Screen* m_pScreen;

	public:
		static HomePage* homePage();

		ftxui::Component component;

		HomePage(HomePage& other) = delete;
		void operator = (const HomePage&) = delete;
	};
};


#endif // !QZHOMEPAGE
