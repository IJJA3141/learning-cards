#include <ftxui/component/screen_interactive.hpp>

#include "game.hpp"

qz::hub::hub(std::string _listName)
{
	m_list = qz::list::get(_listName);

	std::function<void()> placeholder;

	m_bWrite = ftxui::Button("Write", placeholder);
	m_bCard = ftxui::Button("Card", placeholder);
	m_bTrueFalse = ftxui::Button("True False", placeholder);
	m_bChoose = ftxui::Button("Choose", placeholder);
	m_bAdd = ftxui::Button("Add", placeholder);
	m_bEdit = ftxui::Button("Edit", placeholder);
	m_bDelete = ftxui::Button("Delete", placeholder);
	m_bHome = ftxui::Button("Home", placeholder);
	m_bQuit = ftxui::Button("Quit", placeholder);

	m_mTheme = ftxui::Menu(&m_vStrTheme, &m_menuIndex);
	m_mVersion = ftxui::Menu(&m_vStrVersion, &m_menuIndex);

	m_container = ftxui::Container::Vertical({ m_bWrite, m_bCard, m_bTrueFalse, m_bChoose, m_bAdd, m_bEdit, m_bDelete, m_bHome, m_bQuit });

	std::function<ftxui::Element()> renderer = [&]
	{
		int x = ftxui::ScreenInteractive::Active()->dimx();
		int space = x - 2 * std::floor(x / 2);

		m_vStrTheme.clear();
		m_vStrVersion.clear();

		for (qz::pair pair : m_list.vP)
		{
			m_vStrTheme.push_back(pair.theme);
			m_vStrVersion.push_back(pair.version);
		}

		return ftxui::hbox(
		{
			ftxui::vbox(ftxui::vscroll_indicator(ftxui::frame(ftxui::hbox(
			{
				m_mTheme->Render(),
				m_mVersion->Render(),
			}
			)))) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, x / 2),

			ftxui::filler() | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, space),
			
			ftxui::vbox(
			{
				ftxui::vbox(
				{
					ftxui::hbox({m_bWrite->Render(), m_bCard->Render(),}),
					ftxui::hbox({m_bTrueFalse->Render(), m_bChoose->Render(),}),
				}),
				m_bAdd->Render(),
				m_bEdit->Render(),
				m_bDelete->Render(),
				ftxui::hbox({m_bHome->Render(), m_bQuit->Render(),}),
			}
			) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, x / 2)
		});
	};

	m_renderer = ftxui::Renderer(m_container, renderer);

	return;
}
