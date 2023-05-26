#pragma once

#ifndef QZDELETE
#define QZDELETE

#include "ftxui/component/component.hpp"
#include <string>

#include "screen.h"

namespace qz
{
	class DeletePage
	{
	private:
		DeletePage(ftxui::Component* _pHomePage);
		static DeletePage* m_pDeletePage;

		qz::Screen* m_pScreen;
		ftxui::Component* m_pHomePage;
		ftxui::Component* m_pParent;

		ftxui::Component m_component;

	public:
		static DeletePage* deletePage(ftxui::Component* _pHomePage);

		ftxui::Component buttons;
		std::string list;
		int index;

		ftxui::Component* component(int _index, std::string _list, ftxui::Component* _pParent);

		DeletePage(DeletePage& other) = delete;
		void operator = (const DeletePage&) = delete;
	};
}
#endif // !QZDELETE
