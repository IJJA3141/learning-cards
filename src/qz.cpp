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
	list a = list::get("test");

	std::cout << a;

	return a.save();
}