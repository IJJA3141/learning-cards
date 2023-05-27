#include "quit.h"

qz::Quit* qz::Quit::m_quitPage = nullptr;

qz::Quit::Quit()
{
	this->m_pScreen = qz::Screen::screen();
	this->m_pParent = nullptr;

	this->m_buttons = ftxui::Container::Horizontal(
	{
		//Quit button
		ftxui::Button("Yes", [&]
		{
			//
			//		/!\
			//
			// add saving system
			//

			this->m_pScreen->stop();
			return;
		}),

		//Back button
		ftxui::Button("No", [&]
		{
			this->m_pScreen->swap(this->m_pParent);
			return;
		}),
	});

	this->m_component = ftxui::Renderer(this->m_buttons, [&]
		{
			return ftxui::window(ftxui::text("<| Qz |>") | ftxui::center,
				{
					ftxui::vbox(
					{
						ftxui::text("Are you sure you want to exit ?") | ftxui::center,
						this->m_buttons->Render() | ftxui::center,
					}) | ftxui::center
				});
		});

	return;
}

qz::Quit* qz::Quit::quit()
{
	if (qz::Quit::m_quitPage == nullptr) qz::Quit::m_quitPage = new Quit();

	return qz::Quit::m_quitPage;
}

ftxui::Component* qz::Quit::get(ftxui::Component* _pParent)
{
	this->m_pParent = _pParent;

	return &this->m_component;
}