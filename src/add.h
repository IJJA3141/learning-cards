#pragma once

#ifndef QZADD
#define QZADD

#include "ftxui/component/component.hpp"

#include "screen.h"

#include <string>

namespace qz
{
	class AddPage
	{
	private:
		AddPage();
		static AddPage* m_pAddPage;

		ftxui::Component m_buttons;
		ftxui::Component m_component;
		ftxui::Component m_errorText;

		std::string m_input;
		bool m_bool;

	public:
		static AddPage* addPage();

		ftxui::Component component;

		AddPage(AddPage& other) = delete;
		void operator = (const AddPage&) = delete;
	};
}

#endif // !QZADD
