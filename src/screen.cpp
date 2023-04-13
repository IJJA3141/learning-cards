#include "screen.h"

ftxui::ScreenInteractive qz::Screen::m_screen = ftxui::ScreenInteractive::Fullscreen();
ftxui::Component* qz::Screen::m_pComponent = nullptr;
qz::Screen* qz::Screen::screen_ = nullptr;

qz::Screen::Screen(ftxui::Component* _pComponent)
{
	qz::Screen::m_pComponent = _pComponent;
	this->m_end = false;

	return;
}

qz::Screen* qz::Screen::screen(ftxui::Component* _pComponent)
{
	if (qz::Screen::screen_ == nullptr)
	{
		qz::Screen::screen_ = new qz::Screen(_pComponent);
	}

	return qz::Screen::screen_;
}

void qz::Screen::start()
{
	this->m_end = false;

	while (!qz::Screen::m_end)
	{
		qz::Screen::m_screen.Loop(*qz::Screen::m_pComponent);
	};

	return;
}

void qz::Screen::stop()
{
	this->m_end = true;
	qz::Screen::m_screen.Exit();

	return;
}

void qz::Screen::swap(ftxui::Component* _pComponent)
{
	this->m_pComponent = _pComponent;
	qz::Screen::m_screen.Exit();

	return;
}