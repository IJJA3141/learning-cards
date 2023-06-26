#pragma once
#ifndef LIST
#define LIST

#include <string>
#include <vector>

#include "pair.hpp"

namespace qz
{
	class list
	{
	public:
		std::string name;
		int score;
		std::vector<qz::pair> vP;

		static list get(std::string _name);
		static list make(std::string _name);

		bool operator<<(qz::pair& _pair);

		int save();

		list();
	private:
		list(std::string _name, int _score);
	};
};

std::ostream& operator<<(std::ostream& _stream, const qz::list* _list);
std::ostream& operator<<(std::ostream& _stream, const qz::list& _list);

#endif //!LIST