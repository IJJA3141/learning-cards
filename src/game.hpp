#pragma once
#ifndef GAME
#define GAME

#include <string>

#include <ftxui/component/component.hpp>

#include "list.hpp"

namespace qz
{
	class hub : public ftxui::ComponentBase
	{
	public:
		hub(std::string _listName);
		inline ftxui::Element Render() { return this->m_renderer->Render(); };

		ftxui::Component m_renderer, m_container;
	private:
		//
		// b prefix for button
		// m prefix for menu
		//
		ftxui::Component m_bWrite, m_bCard, m_bTrueFalse, m_bChoose, m_bAdd, m_bEdit, m_bDelete, m_bHome, m_bQuit;
		ftxui::Component m_mTheme, m_mVersion;

		qz::list m_list;

		std::vector<std::string> m_vStrTheme, m_vStrVersion;
		int m_menuIndex;
	};
}

#endif // !GAME
