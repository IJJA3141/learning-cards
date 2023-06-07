#pragma once

#ifndef QZHOMEPAGE
#define QZHOMEPAGE

#include "ftxui/component/component.hpp"

#include <vector>
#include <string>

#include "iPage.hpp"
#include "screen.hpp"

namespace qz
{
	class HomePage : public iPage
	{
	private:
		HomePage();
		static HomePage* m_pHomePage;

		int m_listIndex;
		std::vector<std::string> m_list;

		ftxui::Component m_menu;
		ftxui::Component m_buttons;
		ftxui::Component m_buttonsMenu;

		static qz::Screen* m_pScreen;
	public:
		static HomePage* homePage();
		
		static qz::iPage* m_pPlay;

		ftxui::Component* get(std::string _arg) override;

		ftxui::Component component;

		HomePage(HomePage& other) = delete;
		void operator = (const HomePage&) = delete;
	};
};

#endif // !QZHOMEPAGE