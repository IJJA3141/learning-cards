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

		bool m_bool;

	public:
		static AddPage* addPage();

		ftxui::Component component;

		AddPage(AddPage& other) = delete;
		void operator = (const AddPage&) = delete;
	};
}

#endif // !QZADD
