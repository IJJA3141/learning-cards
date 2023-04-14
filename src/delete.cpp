#include "delete.h"

qz::DeletePage* qz::DeletePage::m_pDeletePage = nullptr;

qz::DeletePage::DeletePage(ftxui::Component* _pHomePage, qz::Screen** _ppScreen)
{
	this->m_ppScreen = _ppScreen;
	this->m_pHomePage = _pHomePage;
	this->m_pParent = nullptr;
	this->list = "";

	this->buttons = ftxui::Container::Horizontal(
		{
			ftxui::Button("Delete", [&] {deleteList(this->list.c_str()); ((qz::Screen*)*_ppScreen)->swap(this->m_pHomePage); return; }),
			ftxui::Renderer([]{return ftxui::filler() | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 10); }),
			ftxui::Button("Cancel",  [&] {((qz::Screen*)*_ppScreen)->swap(this->m_pParent); return; }),
		});

	this->m_component = ftxui::Renderer(this->buttons, [&]
		{
			return ftxui::window(ftxui::text("<| Qz |>") | ftxui::center,
				{
					ftxui::vbox(
						{
							ftxui::text("Are you sure you want to delete " + this->list + "?") | ftxui::center,
							ftxui::text("You won't be able to recover it.") | ftxui::center ,
							ftxui::filler() | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, 2),
							this->buttons->Render() | ftxui::center,
						}) | ftxui::center,
				});
		});

	return;
}

qz::DeletePage* qz::DeletePage::deletePage(ftxui::Component* _pHomePage, qz::Screen** _ppScreen)
{
	if (qz::DeletePage::m_pDeletePage == nullptr)
	{
		qz::DeletePage::m_pDeletePage = new DeletePage(_pHomePage, _ppScreen);
	}

	return qz::DeletePage::m_pDeletePage;
}

ftxui::Component* qz::DeletePage::component(std::string _list, ftxui::Component* _pParent)
{
	this->m_pParent = _pParent;
	this->list = _list;

	return &this->m_component;
}
