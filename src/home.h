#pragma once

class homePage 
{
public:
	// components
	ftxui::Component m_compAll;
	ftxui::Component m_buttons;
	ftxui::Component m_menu;
	ftxui::Component m_yes;
	ftxui::Component m_no;

	// private variables
	std::vector<std::string> m_lists;
	int m_dropDownSelect;
	
	// pointers
	ftxui::ScreenInteractive* m_pScreen;
	ftxui::Component** m_pPNextComp;
	bool* m_pEnd;

	ftxui::Component page;
	ftxui::Component delPage;

	homePage(ftxui::ScreenInteractive* _pScreen, ftxui::Component** _pPNextComp, bool* _pEnd);
	~homePage();
};