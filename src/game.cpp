#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

#include "game.hpp"

qz::Game::Game(std::vector<qz::pair>* _pVPair)
{
	this->pVPair = _pVPair;
	this->repetition = MAXSIZE;
	this->error = NOERROR;
	this->score = 0;

	return;
}

void qz::Game::write()
{
	int i = 0;
	int max = this->repetition;
	
	if (this->repetition == -1 || this->repetition > this->pVPair->size()) max = this->pVPair->size();
	this->score -= max / 2;

	ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();

	std::string strInput;
	ftxui::Component compInput = ftxui::Input(&strInput, "");
	ftxui::Component renderer = ftxui::Renderer(compInput, [&]
	{
		return ftxui::vbox(
		{
			ftxui::text(this->pVPair->at(i).theme),
			ftxui::separator(),
				compInput->Render(),
		});
	});

	renderer |= ftxui::CatchEvent([&](ftxui::Event _event)
	{
		if (_event == ftxui::Event::Return) screen.Exit();
		return false;
	});
	
	for (i = 0; i < max; i++)
	{
		screen.Loop(renderer);
		if (strInput == this->pVPair->at(i).version)
		{
			score++;
			this->pVPair->at(i).accuracy++;
		}
		else this->pVPair->at(i).accuracy--;
		strInput = "";
	}

	std::sort(this->pVPair->begin(), this->pVPair->end());

	return;
}