#include "screen.h"

qz::sScreen* qz::sScreen::m_pSScreen = nullptr;
ftxui::ScreenInteractive qz::sScreen::m_screen = ftxui::ScreenInteractive::Fullscreen();

qz::sScreen::sScreen()
{
	this->m_endState = false;
	this->m_initState = false;
	this->m_pComponent = nullptr;

	return;
};

qz::sScreen* qz::sScreen::get()
{
	if (qz::sScreen::m_pSScreen == nullptr) qz::sScreen::m_pSScreen = new qz::sScreen();
	return qz::sScreen::m_pSScreen;
};

void qz::sScreen::init(ftxui::Component* _pComponent)
{
	if (this->m_initState) return;
	this->m_initState = true;
	this->m_pComponent = _pComponent;
	return;
};

void qz::sScreen::start()
{
	if (!this->m_initState) throw "not initialized";
	
	while (!this->m_endState)
	{
		qz::sScreen::m_screen.Loop(*this->m_pComponent);
	};

	return;
};

void qz::sScreen::stop()
{
	this->m_endState = true;
	qz::sScreen::m_screen.Exit();
};

void qz::sScreen::swap(ftxui::Component* _pComponent)
{
	this->m_pComponent = _pComponent;
	qz::sScreen::m_screen.Exit();

	return;
};