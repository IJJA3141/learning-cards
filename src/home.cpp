#include <string>
#include <vector>
#include <iostream>

#include "readAndWrite.h"

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Button, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/component_options.hpp"   // for ButtonOption
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for operator|, text, Element, hbox, separator, size, vbox, border, frame, vscroll_indicator, HEIGHT, LESS_THAN

#include "home.h"

homePage::homePage(ftxui::ScreenInteractive* _pScreen, ftxui::Component* _pNextComp, bool* _pEnd)
{
	// save pointers
	this->m_pScreen = _pScreen;
	this->m_pNextComp = _pNextComp;
	this->m_pEnd = _pEnd;

	// set private variables
	getLists(_PATH_LISTS, &this->m_lists);
	this->m_dropDownSelect = 0;

	// set menu
	this->m_menu = ftxui::Menu(&this->m_lists, &this->m_dropDownSelect);

	// set buttons
	this->m_buttons = ftxui::Container::Vertical({
		ftxui::Button("Play", [&]
			{
				//this->m_pNextComp = & play page
				this->m_pScreen->Exit();
			}),

		ftxui::Button("Add List", [&] 
			{
				//this->m_pNextComp = & add page
				this->m_pScreen->Exit();
			}),

		ftxui::Button("Edit", [&]
			{
				//this->m_pNextComp = & edit page this->m_lists[this->m_dropDownSelect]
				this->m_pScreen->Exit();
			}),

		ftxui::Button("Delet", [&] 
			{
				//this->m_pNextComp = & delete page
				this->m_pScreen->Exit();
			}),

		ftxui::Button("Settings", [&] 
			{
				//this->m_pNextComp = & settings page
				this->m_pScreen->Exit();
			}),

		ftxui::Button("Quit", [&] 
			{
				*this->m_pEnd = true;
				this->m_pScreen->Exit();
			}),
		}) | ftxui::vcenter | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, 20) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20);

	// put menu and buttons in one component
	this->m_compAll = ftxui::Container::Horizontal({ this->m_buttons, this->m_menu, });

	// page
	this->page = ftxui::Renderer(this->m_compAll, [&]
		{
			return ftxui::window(ftxui::text(L"<| Qz ଳ ​|>") | ftxui::bold | ftxui::center,
			ftxui::hbox(
				{
					ftxui::hbox(
						{
							this->m_buttons->Render() | ftxui::border | ftxui::center | ftxui::flex,
						}
						) | ftxui::flex,
					ftxui::vbox(
						{
							ftxui::vbox(
								{
									ftxui::text("> " + this->m_lists[this->m_dropDownSelect]),
									ftxui::separator(),
									this->m_menu->Render() | ftxui::vscroll_indicator | ftxui::frame
								}
							) | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, 20) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20) | ftxui::border | ftxui::center | ftxui::flex,
						}
					) | ftxui::flex,
				}
			)
			);
		}
	);
}

homePage::~homePage()
{
	setLists(_PATH_LISTS".txt", &this->m_lists);
	return;
}