#include "home.h"

qz::HomePage* qz::HomePage::m_pHomePage = nullptr;

qz::HomePage::HomePage(qz::Screen** _ppScreen)
{
	this->m_pRaw = qz::Raw::raw(&this->m_list);

	this->m_pRaw->getLists();

	this->m_pDeletePage = qz::DeletePage::deletePage(&this->component);
	this->m_pAddPage = qz::AddPage::addPage();

	this->m_lists = ftxui::Menu(&this->m_list, &this->m_listPos) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20);

	this->m_buttons = ftxui::Container::Vertical(
		{
			ftxui::Button("Play",	 [&] {}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),
			ftxui::Button("Eddit",	 [&] {}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),
			ftxui::Button("Add",	 [=] {((qz::Screen*)*_ppScreen)->swap(&this->m_pAddPage->component); }) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),
			ftxui::Button("Delete",	 [=] {((qz::Screen*)*_ppScreen)->swap(this->m_pDeletePage->component(this->m_listPos, this->m_list[this->m_listPos], &this->component)); }) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),
			ftxui::Button("Settings",[&] {}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),
			ftxui::Button("Quit",	 [=] {((qz::Screen*)*_ppScreen)->stop(); return; }) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),
		}) | ftxui::center | ftxui::border;

	this->m_comp = ftxui::Container::Horizontal(
		{
			this->m_buttons, this->m_lists,
		});
	
	this->component = ftxui::Renderer(this->m_comp, [&]
		{
			return ftxui::window(ftxui::text("<| Qz |>") | ftxui::center,
				{
					ftxui::hbox(
						{
							this->m_buttons->Render(),
							ftxui::filler() | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 40),
							vbox(ftxui::text("> " + this->m_list[this->m_listPos]),
								 ftxui::separator(), ftxui::frame(ftxui::vscroll_indicator(this->m_lists->Render())
								 )) | ftxui::border,
						}) | ftxui::center,
				});
		});

	return;
}

qz::HomePage* qz::HomePage::homePage(qz::Screen** _ppScreen)
{
	if (_ppScreen == nullptr && qz::HomePage::m_pHomePage == nullptr) throw std::invalid_argument("HomePage need to be initialized with a pointer to a pointer to a Screen");
	if (qz::HomePage::m_pHomePage == nullptr)
	{
		qz::HomePage::m_pHomePage = new HomePage(_ppScreen);
	}

	return qz::HomePage::m_pHomePage;
}