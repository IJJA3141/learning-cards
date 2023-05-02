#include "home.h"

qz::sHomePage* qz::sHomePage::m_pSHomePage = nullptr;

qz::sHomePage::sHomePage()
{
	this->m_pScreen = qz::sScreen::get();
	this->m_pRaw = qz::Raw::raw(&this->lists);
	this->m_pRaw->getLists();

	this->m_pAddPage = qz::AddPage::addPage();
	this->m_pDeletePage = qz::DeletePage::get();

	this->m_lists = ftxui::Menu(&this->lists, &this->index) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20);

	this->m_buttons = ftxui::Container::Vertical(
		{
			ftxui::Button("Play",		[=] {})
			| ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),

			ftxui::Button("Eddit",		[=] {})
			| ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),

			ftxui::Button("Add",		[=] { this->m_pScreen->swap(&this->m_pAddPage->component); })
			| ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),

			ftxui::Button("Delete",		[=] { this->m_pScreen->swap(&this->m_pDeletePage->component); })
			| ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),

			ftxui::Button("Settings",	[=] {})
			| ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),

			ftxui::Button("Quit",		[=] { this->m_pScreen->stop(); })
			| ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20),

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
							ftxui::vbox(ftxui::text("> " + this->lists[this->index]),
										ftxui::separator(), 
										ftxui::frame(ftxui::vscroll_indicator(this->m_lists->Render())
							)) | ftxui::border,
						}) | ftxui::center,
				});

		});

	return;
};

qz::sHomePage* qz::sHomePage::get()
{
	if (qz::sHomePage::m_pSHomePage == nullptr) qz::sHomePage::m_pSHomePage = new sHomePage();
	return qz::sHomePage::m_pSHomePage;
}