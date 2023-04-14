#pragma once

#ifndef QZDELETE
#define QZDELETE

#include "ftxui/component/component.hpp"
#include <string>

#include "readAndWrite.h"
#include "screen.h"

namespace qz
{
	class DeletePage
	{
	private:
		DeletePage(ftxui::Component* _pHomePage, qz::Screen** _ppScreen);
		static DeletePage* m_pDeletePage;

		qz::Screen** m_ppScreen;
		ftxui::Component* m_pHomePage;
		ftxui::Component* m_pParent;

		ftxui::Component m_component;

	public:
		static DeletePage* deletePage(ftxui::Component* _pHomePage, qz::Screen** _ppScreen);

		ftxui::Component buttons;
		std::string list;

		ftxui::Component* component(std::string _list, ftxui::Component* _pParent);

		DeletePage(DeletePage& other) = delete;
		void operator = (const DeletePage&) = delete;
	};
}
#endif // !QZDELETE
