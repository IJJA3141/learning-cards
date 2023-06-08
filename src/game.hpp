#pragma once
#ifndef GAME
#define GAME

#define MAXSIZE -1;
#define NOERROR -1;

#include <vector>

#include "pair.hpp"

namespace qz 
{
	class Game
	{
	public:
		Game(std::vector<Pair>* _pVPair);

		int repetition, error, score;
		std::vector<Pair>* pVPair;

		void write();
	};
}

#endif // !GAME
