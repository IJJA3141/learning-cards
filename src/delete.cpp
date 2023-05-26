#include "delete.h"

qz::DeletePage* qz::DeletePage::m_pDeletePage = nullptr;

qz::DeletePage::DeletePage(ftxui::Component* _pHomePage)
{
	this->m_pScreen = qz::Screen::screen();
	this->m_pHomePage = _pHomePage;
	this->m_pParent = nullptr;
	this->list = "";

	return;
}

qz::DeletePage* qz::DeletePage::deletePage(ftxui::Component* _pHomePage)
{
	if (qz::DeletePage::m_pDeletePage == nullptr) qz::DeletePage::m_pDeletePage = new DeletePage(_pHomePage);

	return qz::DeletePage::m_pDeletePage;
}

ftxui::Component* qz::DeletePage::component(int _index, std::string _list, ftxui::Component* _pParent)
{
	this->m_pParent = _pParent;
	this->index = _index;
	this->list = _list;

	return &this->m_component;
}





//		
//		ftxui::Container::Horizontal(
//			{
//				ftxui::Button("Delete", [&] {this->m_pRaw->deleteList(this->index); this->m_pScreen->swap(this->m_pHomePage); return; }),
//				ftxui::Renderer([] {return ftxui::filler() | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 10); }),
//				ftxui::Button("Cancel",  [&] {this->m_pScreen->swap(this->m_pParent); return; }),
//			});
//		
//		ftxui::Renderer(this->buttons, [&]
//			{
//				return ftxui::window(ftxui::text("<| Qz |>") | ftxui::center,
//					{
//						ftxui::vbox(
//							{
//								ftxui::text("Are you sure you want to delete " + this->list + "?") | ftxui::center,
//								ftxui::text("You won't be able to recover it.") | ftxui::center ,
//								ftxui::filler() | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, 2),
//								this->buttons->Render() | ftxui::center,
//							}) | ftxui::center,
//					});
//			});