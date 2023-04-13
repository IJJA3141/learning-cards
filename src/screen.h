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
		Screen(ftxui::Component* _pComponent);
		
		static Screen* screen_;
		static ftxui::ScreenInteractive m_screen;
		bool m_end;
	

		static ftxui::Component* m_pComponent;


	public:
		static Screen* screen(ftxui::Component* _pComponent);

		void start();
		void stop();
		void swap(ftxui::Component* _pComponent);

		Screen(Screen& other) = delete;
		void operator = (const Screen&) = delete;
	};
};

#endif // !QZSCREEN