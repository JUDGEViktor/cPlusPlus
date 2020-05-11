#pragma once

#include "resource.h"
#include "Header.h"
#include "GameMob.h"
#include "Cell.h"

enum directions {
	NORTH,
	SOUTH,
	WEST,
	EAST
};

class PacMan : public GameMob {

private:

	directions DIRECTION;

public:

	void SpawnPacMan() {
		GameMob(make_pair(2.0 * SQUARE_SIZE, 7.0 * SQUARE_SIZE));
	}

	void ChangeDirection(directions newDirection) {
		DIRECTION = newDirection;
	}

	bool TestStep(vector<vector<Cell>> Maze) {

		switch (DIRECTION) {
		case NORTH:
			return Maze[GetCOORD().first][GetCOORD().second - 1].IsFreee();
			break;
		case SOUTH:
			return Maze[GetCOORD().first][GetCOORD().second + 1].IsFreee();
			break;
		case WEST:
			return Maze[GetCOORD().first - 1][GetCOORD().second].IsFreee();
			break;
		case EAST:
			return Maze[GetCOORD().first + 1][GetCOORD().second].IsFreee();
			break;
		}


	}

	void Move(vector<vector<Cell>> Maze, directions newDirection) {

		switch (DIRECTION) {
		case NORTH:
			if (TestStep(Maze) == true)
				GetCOORD().second -= 1;
			break;
		case SOUTH:
			if (TestStep(Maze) == true)
				GetCOORD().second += 1;
			break;
		case WEST:
			if (TestStep(Maze) == true)
				GetCOORD().first -= 1;
			break;
		case EAST:
			if (TestStep(Maze) == true)
				GetCOORD().first += 1;
			break;
		}
	}

};
