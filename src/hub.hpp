#pragma once
#ifndef HUB
#define HUB

#include <string>

#include "renderer.hpp"
#include "list.hpp"

namespace qz
{
	class Hub : public qz::iScene
	{
	public:
		Hub(std::string _listName);

	private:
		// v = vector
		// str = string
		// b = button
		// m = menu
		ftxui::Component container_, renderer_;
		ftxui::Component bWrite_, bCard_, bTrueFalse_, bChoose_, bAdd_, bEdit_, bDelete_, bHome_, bQuit_;
		ftxui::Component mTheme_, mVersion_;
		int menuIndex_;

		std::string listName_;
		qz::list list_;

		std::vector<std::string> vStrTheme_, vStrVersion_;
	};
}

#endif // !HUB
