#include "home.hpp"

qz::HomePage* qz::HomePage::m_pHomePage = nullptr;

qz::HomePage::HomePage()
{
	this->m_listIndex = 0;

	// temporaire
	this->m_list =
	{
		"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
		"10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
		"20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
		"30", "31", "32", "33", "34", "35", "36", "37", "38", "39",
		"40", "41", "42", "43", "44", "45", "46", "47", "48", "49",
		"50", "51", "52", "53", "54", "55", "56", "57", "58", "59",
	};

	this->m_menu = ftxui::Menu(&this->m_list, &this->m_listIndex) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20);

	this->m_buttons = ftxui::Container::Vertical(
		{
			// --> Play page
			ftxui::Button("Play", [&]
			{
				this->m_pScreen->swap(this->m_pPlay->get("test"));
				return;

			}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),


				// --> Eddit page
				ftxui::Button("Eddit", [&]
				{
						// some stuff

					}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),


					// --> Add popup	
					ftxui::Button("Add", [&]
					{
						this->m_pScreen->swap(&this->component);
						return;

					}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),


						// --> Delete popup
						ftxui::Button("Delete", [&]
						{
								// some stuff

							}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),


							// --> Settings Page
							ftxui::Button("Settings", [&]
							{
									// some stuff

								}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),


								// --> Quit popup	
								ftxui::Button("Quit", [&]
								{
									this->m_pScreen->swap(this->m_pQuitPage->get(&this->component));
									return;

								}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),

		}) | ftxui::center | ftxui::border;

	this->m_buttonsMenu = ftxui::Container::Horizontal(
		{
			this->m_buttons,
			this->m_menu,
		});

	this->component = ftxui::Renderer(this->m_buttonsMenu, [&]
		{
			return ftxui::window(ftxui::text("<| Qz |>") | ftxui::center,
				{
					ftxui::hbox(
					{
						this->m_buttons->Render(),
						ftxui::filler() | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 40),
						vbox(
							ftxui::text("> " + this->m_list[this->m_listIndex]),
							ftxui::separator(),
							ftxui::frame(ftxui::vscroll_indicator(this->m_menu->Render())
						)) | ftxui::border,
					}) | ftxui::center,
				});
		});

	return;
}

qz::HomePage* qz::HomePage::homePage()
{
	if (qz::HomePage::m_pHomePage == nullptr) qz::HomePage::m_pHomePage = new HomePage();

	return qz::HomePage::m_pHomePage;
}