#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

#include "debug.hpp"

#include "hub.hpp"
#include "list.hpp"

int main()
{
	qz::Hub a = qz::Hub("test");
	ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();

	screen.Loop(a.Renderer);

	return 0;
}
