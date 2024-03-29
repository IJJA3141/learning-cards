#pragma once

#ifndef QZSCREEN
#define QZSCREEN

#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component.hpp"

namespace qz
{
	class Screen
	{
	private:
		Screen();

		static Screen* screen_;
		static ftxui::ScreenInteractive m_screen;
		bool m_end;

		static ftxui::Component* m_pComponent;
		ftxui::Component* m_pPreviousComponent;

		ftxui::Component m_quit;
		ftxui::Component m_buttons;

	public:
		static Screen* screen();

		void start(ftxui::Component* _pComponent);
		void stop();
		void quit();
		void swap(ftxui::Component* _pComponent);
		void back();

		Screen(Screen& other) = delete;
		void operator = (const Screen&) = delete;
	};
};

#endif // !QZSCREEN