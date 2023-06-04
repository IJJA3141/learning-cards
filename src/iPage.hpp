#pragma once

#ifndef PAGE
#define PAGE

#include <ftxui/component/component.hpp>
#include <string>

namespace qz
{
	class iPage
	{
	public:
		virtual ftxui::Component* get(std::string _arg) = 0;
	};
}

#endif // !PAGE
