#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>

#include "pair.hpp"
#include "game.hpp"

struct list
{
public:
	list(std::string _name, int _score, std::vector<qz::Pair>* _pVPair);

	std::vector<qz::Pair>* pVPair;
	std::string name;
	int score;

};

list::list(std::string _name, int _score, std::vector<qz::Pair>* _pVPair)
{
	this->pVPair = _pVPair;
	this->name = _name;
	this->score = 0;
}

int saveList(const list& _list)
{
	std::string url = "./lists/" + _list.name + ".txt";

	std::cout << url << "\n";

	std::fstream fs;
	fs.open(url, std::ios::in | std::ios::out);
	if (fs.is_open())
	{
		fs.clear();
		fs << _list.name << "\n" << _list.score << "\n";
		for (int i = 0; i < _list.pVPair->size(); i++)
		{
			fs << _list.pVPair->at(i) << "\n";
		}
		fs.close();
		return 0;
	}
	return 1;
}

int main()
{
	std::vector<qz::Pair> a = { qz::Pair("1", "1", 5), qz::Pair("2", "2", 6), qz::Pair("3", "3", 10), qz::Pair("alef", "sahdfldks", 453) };

	list b = list("test", 7, &a);

	return saveList(b);
}