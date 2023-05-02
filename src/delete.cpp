#include "delete.h"

qz::sDeletePage* qz::sDeletePage::m_pDeletePage = nullptr;

qz::sDeletePage::sDeletePage()
{
	this->m_pScreen = qz::sScreen::get();
	this->m_pHomePage = qz::sHomePage::get();
	this->m_pRaw = qz::Raw::raw(nullptr);

	this->m_buttons = ftxui::Container::Horizontal(
		{
			ftxui::Button("Delete", [&] {this->m_pRaw->deleteList(this->m_pHomePage->index)})
		});

	return;
};

qz::sDeletePage* qz::sDeletePage::get()
{
	if (qz::sDeletePage::m_pDeletePage == nullptr) qz::sDeletePage::m_pDeletePage = new sDeletePage();
	return qz::sDeletePage::m_pDeletePage;
}