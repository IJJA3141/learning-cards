#pragma once
#ifndef PAIR
#define PAIR

#include <string>
#include <iostream>

namespace qz 
{
	class pair
	{
	public:
		pair(std::string _theme, std::string _version, int _accuracy = 0);

		std::string theme, version;
		int accuracy;

		bool operator<(const pair& _pair);
		bool operator>(const pair& _pair);
		bool operator==(const pair& _pair);
	};
}

std::ostream& operator<<(std::ostream& _stream, const qz::pair& _pair);

#endif // !PAIR
