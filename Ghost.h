#pragma once
#include "Header.h"
#include "GameMob.h"
#include "PacMan.h"
#include "Cell.h"



class Ghost : public GameMob {

private:

	float ManhattanDistance(coordinates src, coordinates dst) {
		return abs(src.first - dst.first) + abs(src.second - dst.second);
	}

public:

	Ghost() : GameMob(make_pair(15.0 * SQUARE_SIZE, 15.0 * SQUARE_SIZE)) {}

	coordinates FindPacMan(vector<vector<Cell>> Maze, PacMan pacMan) {

		//Check north
		if (ManhattanDistance(make_pair(GetCOORD().first, GetCOORD().second - 1), pacMan.GetCOORD()) < ManhattanDistance(GetCOORD(), pacMan.GetCOORD())
			&& Maze[GetCOORD().first][GetCOORD().second - 1].IsFreee())
			return make_pair(GetCOORD().first, GetCOORD().second - 1);

		//Check south
		else if (ManhattanDistance(make_pair(GetCOORD().first, GetCOORD().second + 1), pacMan.GetCOORD()) < ManhattanDistance(GetCOORD(), pacMan.GetCOORD())
			&& Maze[GetCOORD().first][GetCOORD().second + 1].IsFreee())
			return make_pair(GetCOORD().first, GetCOORD().second + 1);

		//Check west
		else if (ManhattanDistance(make_pair(GetCOORD().first - 1, GetCOORD().second), pacMan.GetCOORD()) < ManhattanDistance(GetCOORD(), pacMan.GetCOORD())
			&& Maze[GetCOORD().first - 1][GetCOORD().second].IsFreee())
			return make_pair(GetCOORD().first - 1, GetCOORD().second);

		//Check east
		else if (ManhattanDistance(make_pair(GetCOORD().first + 1, GetCOORD().second), pacMan.GetCOORD()) < ManhattanDistance(GetCOORD(), pacMan.GetCOORD())
			&& Maze[GetCOORD().first + 1][GetCOORD().second].IsFreee())
			return make_pair(GetCOORD().first + 1, GetCOORD().second);

	}

	bool EatPacman(PacMan pacman) {

		if (GetCOORD() == pacman.GetCOORD()) {

			if (GetStatus() == FRIGHTENED) {
				return false;
			}

			if (GetStatus() == REGULAR) {
				return true;
			}


		}

	}


};
