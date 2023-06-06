#include "quit.hpp"
#include <iostream>

qz::Quit* qz::Quit::m_quitPage = nullptr;

qz::Quit::Quit()
{
	this->m_pScreen = qz::Screen::screen();
	this->debug = "";

	

	return;
}

qz::Quit* qz::Quit::quit()
{
	if (qz::Quit::m_quitPage == nullptr) qz::Quit::m_quitPage = new Quit();

	return qz::Quit::m_quitPage;
}

ftxui::Component* qz::Quit::get(std::string _arg)
{
	this->debug = _arg;
	return &this->m_component;
}