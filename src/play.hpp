#pragma once

#ifndef PLAY
#define PLAY

#include <string>
#include <vector>

#include "ftxui/component/component.hpp"
#include "ftxui/dom/table.hpp"

#include "screen.hpp"
#include "iPage.hpp"

namespace qz
{
	class Play : public iPage
	{
	private:
		static Play* m_play;
		Play();

		ftxui::Component m_component;
		ftxui::Component m_buttons;
		ftxui::Component m_list;
		ftxui::Component m_exit;
		ftxui::Component m_buttonsListExit;
		ftxui::Component m_themeMenu;
		ftxui::Component m_versionMenu;

		std::string m_listName;

		int m_index;

		qz::Screen* m_pScreen;
		qz::Quit* m_pQuit;

	public:
		static Play* play();

		ftxui::Component* get(std::string _list);
		std::vector<std::string> vTheme;
		std::vector<std::string> vVersion;


		Play(Play& other) = delete;
		void operator = (const Play&) = delete;
	};
}

#endif // PLAY