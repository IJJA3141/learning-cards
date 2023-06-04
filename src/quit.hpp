#pragma once

#ifndef QUIT
#define QUIT

#include "ftxui/component/component.hpp"

#include "screen.hpp"

namespace qz
{
	class Quit : public iPage
	{
	private:
		Quit();
		static qz::Quit* m_quitPage;

		qz::Screen* m_pScreen;
		ftxui::Component* m_pParent;
		ftxui::Component m_component;
		ftxui::Component m_buttons;

	public:
		static qz::Quit* quit();

		ftxui::Component* get(ftxui::Component* _pParent);

		Quit(Quit& other) = delete;
		void operator = (const Quit&) = delete;
	};
}

#endif // QUIT