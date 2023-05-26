#include "home.h"

qz::HomePage* qz::HomePage::m_pHomePage = nullptr;

qz::HomePage::HomePage()
{
	this->m_pScreen = qz::Screen::screen();
	this->m_listIndex = 0;
	this->m_list = {"0", "1","2","3", "4", "6", "7", "8", "9", "10"};

	this->m_menu = ftxui::Menu(&this->m_list, &this->m_listIndex);

	this->m_buttons = ftxui::Container::Vertical(
	{
		// --> Play page
		ftxui::Button("Play", [&] 
		{
			// some stuff
		
		}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),

		
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
			this->m_pScreen->stop();
			return;

		}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),

	}) | ftxui::center | ftxui::border;

	this->m_buttonsMenu = ftxui::Container::Vertical(
	{
		this->m_buttons,
		this->m_menu,
	});

	this->component = ftxui::Renderer(this->m_buttons, [&]
	{
		return ftxui::window(ftxui::text("<| Qz |>") | ftxui::center,
		{
			ftxui::hbox(
			{
				this->m_buttons->Render(),
				ftxui::filler() | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 40),
				ftxui::vbox(
				{
					ftxui::text("> " + this->m_list[this->m_listIndex]),
					ftxui::separator(),
					ftxui::frame(ftxui::vscroll_indicator(this->m_menu->Render())) | ftxui::border,
				}) | ftxui::center
			})
		});
	});

	return;
}

qz::HomePage* qz::HomePage::homePage()
{
	if (qz::HomePage::m_pHomePage == nullptr) qz::HomePage::m_pHomePage = new HomePage();

	return qz::HomePage::m_pHomePage;
}









//	ftxui::Menu(&this->m_list, &this->m_listPos) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20);
//	
//	m_buttons = ftxui::Container::Vertical(
//		{
//			ftxui::Button("Play",	 [&] {}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),
//			ftxui::Button("Eddit",	 [&] {}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),
//			ftxui::Button("Add",	 [=] {pScreen->swap(&this->m_pAddPage->component); }) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),
//			ftxui::Button("Delete",	 [=] {pScreen->swap(this->m_pDeletePage->component(this->m_listPos, this->m_list[this->m_listPos], &this->component)); }) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),
//			ftxui::Button("Settings",[&] {}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),
//			ftxui::Button("Quit",	 [=] {pScreen->stop(); return; }) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),
//		}) | ftxui::center | ftxui::border;
//	
//	ftxui::Container::Horizontal(
//		{
//			this->m_buttons, this->m_lists,
//		});
//	
//	ftxui::Renderer(this->m_comp, [&]
//		{
//			return ftxui::window(ftxui::text("<| Qz |>") | ftxui::center,
//				{
//					ftxui::hbox(
//						{
//							this->m_buttons->Render(),
//							ftxui::filler() | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 40),
//							vbox(ftxui::text("> " + this->m_list[this->m_listPos]),
//								 ftxui::separator(), ftxui::frame(ftxui::vscroll_indicator(this->m_lists->Render())
//								 )) | ftxui::border,
//						}) | ftxui::center,
//				});
//		});