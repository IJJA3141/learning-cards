#include <fstream>
#include <iostream>

#include "list.hpp"

qz::list::list(std::string _name, int _score)
{
	this->name = _name;
	this->score = _score;
	this->vP = {};
}

qz::list::list()
{
	this->name = "";
	this->score = NULL;
	this->vP = {};

	return;
}

qz::list::~list()
{
	this->save();

	return;
}

qz::list& qz::list::make(std::string _name)
{
	list a = list(_name, 0);
	return a;
}

bool qz::list::operator<<(qz::pair& _pair)
{
	this->vP.push_back(_pair);
	return false;
}

qz::list qz::list::get(std::string _name)
{
	list out = list(_name, 0);
	std::fstream fs;

	fs.open("./.save/lists/" + _name + ".txt", std::iostream::in);
	if (fs.is_open())
	{
		std::cout << "loaded the list\n";

		std::string str;
		std::getline(fs, str);
		out.score = std::stoi(str);

		std::string theme, version, accuracy;

		while (std::getline(fs, theme))
		{
			std::getline(fs, version);
			std::getline(fs, accuracy);

			out.vP.push_back(qz::pair(theme, version, std::stoi(accuracy)));
		}
		fs.close();
	}
	else std::cout << "didn't load the list" << std::endl;

	return out;
}

int qz::list::save()
{
	std::ofstream file("./.save/lists/" + this->name + ".txt");

	if (file.is_open()) 
	{	
		file.clear();
		file << this->score << "\n";
		file << this;
		file.close();
		return 0;
	}
	else 
	{
		std::cout << "Error opening file." << std::endl;
		return 1;
	}
}

std::ostream& operator<<(std::ostream& _stream, const qz::list* _list)
{
	for (qz::pair pair : _list->vP) _stream << pair << "\n";
	return _stream;
}

std::ostream& operator<<(std::ostream& _stream, const qz::list& _list)
{
	for (qz::pair pair : _list.vP) _stream << pair << "\n";
	return _stream;
}