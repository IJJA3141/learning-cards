#pragma once

class homePage 
{
public:
	// components
	ftxui::Component m_compAll;
	ftxui::Component m_buttons;
	ftxui::Component m_menu;

	// private variables
	std::vector<std::string> m_lists;
	int m_dropDownSelect;
	
	// pointers
	ftxui::ScreenInteractive* m_pScreen;
	ftxui::Component* m_pNextComp;
	bool* m_pEnd;

	ftxui::Component page;

	homePage(ftxui::ScreenInteractive* _pScreen, ftxui::Component* _pNextComp, bool* _pEnd);
	~homePage();
};