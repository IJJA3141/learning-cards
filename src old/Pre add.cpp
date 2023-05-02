#include "add.h"
#include "home.h"
#include "screen.h"

qz::AddPage* qz::AddPage::m_pAddPage = nullptr;

qz::AddPage::AddPage()
{
	this->m_bool = false;

	this->m_errorText = ftxui::Renderer([] { return ftxui::text("nooooooo you can't do this") | ftxui::color(ftxui::Color::Red); }) | ftxui::Maybe(&this->m_bool);

	this->m_buttons = ftxui::Container::Horizontal(
		{
			ftxui::Button("Add", [&] {this->m_bool = true; }),
			ftxui::Button("Cancel", [&] {qz::Screen::screen()->swap(&qz::HomePage::homePage(nullptr)->component); }),
		});

	this->m_component = ftxui::Container::Vertical({
		this->m_errorText,
		ftxui::Input(&this->m_input, "new list name"),
		this->m_buttons
		});
	
	this->component = ftxui::Renderer(this->m_component, [&]
		{
			return ftxui::window(ftxui::text("<| Qz |>") | ftxui::center,
				{
					ftxui::vbox(
						{
							ftxui::text(""),
							this->m_component->Render(),
						}) | ftxui::center,
				});
		});

	return;
}

qz::AddPage* qz::AddPage::addPage()
{
	if (qz::AddPage::m_pAddPage == nullptr)
	{
		qz::AddPage::m_pAddPage = new qz::AddPage();
	};

	return qz::AddPage::m_pAddPage;
};