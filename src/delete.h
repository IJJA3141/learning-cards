#pragma once

#ifndef QZDELETE
#define QZDELETE

#include "ftxui/component/component.hpp"
#include <string>

#include "readAndWrite.h"
#include "screen.h"
#include "home.h"

namespace qz
{
	class sDeletePage
	{
	private:
		sDeletePage();
		static sDeletePage* m_pDeletePage;

		qz::sScreen* m_pScreen;
		qz::sHomePage* m_pHomePage;
		qz::Raw* m_pRaw;

		ftxui::Component m_buttons;

	public:
		static sDeletePage* get();

		ftxui::Component component;

		sDeletePage(sDeletePage& other) = delete;
		void operator = (const sDeletePage&) = delete;
	};
}
#endif // !QZDELETE
