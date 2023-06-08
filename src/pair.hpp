#pragma once
#ifndef PAIR
#define PAIR

#include <string>
#include <iostream>

namespace qz 
{
	class Pair
	{
	public:
		Pair(std::string _theme, std::string _version, int _accuracy = 0);

		std::string theme, version;
		int accuracy;

		bool operator<(const Pair& _pair);
		bool operator>(const Pair& _pair);
		bool operator==(const Pair& _pair);
	};
}

std::ostream& operator<<(std::ostream& _stream, const qz::Pair& _pair);

#endif // !PAIR
