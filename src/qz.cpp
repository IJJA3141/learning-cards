#include <vector>
#include <string>
#include <algorithm>

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>

#include "pair.hpp"

struct Settings
{
public:
	Settings(int _rep, int _maxError);

	int repetition, maxError;

	static const int FULLSIZE = -1;
	static const int NOLIMIT = -1;
};

Settings::Settings(int _rep, int _maxError)
{
	this->maxError = _maxError;
	this->repetition = _rep;
	return;
}

int gameWrite(std::vector<qz::Pair>* _pVPair, Settings _settings)
{
	int max = _settings.repetition;
	if (max == -1 || _settings.repetition > _pVPair->size()) max = _pVPair->size();
	int score = -max/2;
	int i = 0;

	ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();

	std::string strInput;
	ftxui::Component compInput = ftxui::Input(&strInput, "");
	ftxui::Component renderer = ftxui::Renderer(compInput, [&]
	{
		return ftxui::vbox(
		{
			ftxui::text(_pVPair->at(i).theme),
			ftxui::separator(),
				compInput->Render(),
		});
	});

	renderer |= ftxui::CatchEvent([&](ftxui::Event _event)
	{
		if (_event == ftxui::Event::Return) screen.Exit();
		return false;
	});
	std::cout << max;
	for (i = 0; i < max; i++)
	{
		screen.Loop(renderer);
		if (strInput == _pVPair->at(i).version)
		{
			score++;
			_pVPair->at(i).accuracy++;
		}
		else _pVPair->at(i).accuracy--;
		strInput = "";
	}
	std::sort(_pVPair->begin(), _pVPair->end());
	return score;
}



int main()
{
	std::vector<qz::Pair> a = { qz::Pair("",""),qz::Pair("","") ,qz::Pair("","") ,qz::Pair("","") };
	ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();
	Settings b = Settings(Settings::FULLSIZE, Settings::NOLIMIT);

	return gameWrite(&a, b);
}