#include "add.h"
#include "home.h"
#include "screen.h"

qz::AddPage* qz::AddPage::m_pAddPage = nullptr;

qz::AddPage::AddPage()
{
	return;
}

qz::AddPage* qz::AddPage::addPage()
{
	if (qz::AddPage::m_pAddPage == nullptr)	qz::AddPage::m_pAddPage = new qz::AddPage();
	
	return qz::AddPage::m_pAddPage;
};





//	ftxui::Renderer([] { return ftxui::text("nooooooo you can't do this") | ftxui::color(ftxui::Color::Red); }) | ftxui::Maybe(&this->m_bool);
//	
//	ftxui::Container::Horizontal(
//		{
//			ftxui::Button("Add", [&] {this->m_bool = true; }),
//			ftxui::Button("Cancel", [&] {qz::Screen::screen()->swap(&qz::HomePage::homePage()->component); }),
//		});
//	
//	ftxui::Renderer(this->m_component, [&]
//		{
//			return ftxui::window(ftxui::text("<| Qz |>") | ftxui::center,
//				{
//					ftxui::vbox(
//						{
//							ftxui::text(""),
//							this->m_component->Render(),
//						}) | ftxui::center,
//				});
//		});