#pragma once

#ifndef QZSCREEN
#define QZSCREEN

#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component.hpp"

namespace qz
{
	class sScreen
	{
	private:
		sScreen();

		static sScreen* m_pSScreen;
		ftxui::Component* m_pComponent;
		static ftxui::ScreenInteractive m_screen;
		bool m_initState;
		bool m_endState;

	public:
		static sScreen* get();

		void init(ftxui::Component* _pComponent);
		void start();
		void stop();
		void swap(ftxui::Component* _pComponent);

		sScreen(sScreen &other) = delete;
		void operator = (const sScreen&) = delete;
	};
};

#endif // !QZSCREEN