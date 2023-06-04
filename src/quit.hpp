#pragma once

#ifndef QUIT
#define QUIT

#include <string>
#include "ftxui/component/component.hpp"

#include "screen.hpp"
#include "iPage.hpp"

namespace qz
{
	class Quit : public qz::iPage
	{
	private:
		Quit();
		static qz::Quit* m_quitPage;

		qz::Screen* m_pScreen;
		ftxui::Component m_component;
		ftxui::Component m_buttons;

		// debug
		std::string debug;
	public:
		static qz::Quit* quit();

		ftxui::Component* get(std::string _arg) override;

		Quit(Quit& other) = delete;
		void operator = (const Quit&) = delete;
	};
}

#endif // QUIT