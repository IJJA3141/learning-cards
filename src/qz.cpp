#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>

#include "pair.hpp"
#include "game.hpp"
#include "list.hpp"

int main()
{
	qz::hub hubpage = qz::hub("test");
	ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();

	ftxui::Button

	screen.Loop();

	return 0;
}