#pragma once
#include "Header.h"

enum directions {
	NORTH,
	SOUTH,
	WEST,
	EAST,
	STOP
};

class GameMob {

private:

	coordinates COORD;

	directions DIRECTION;

	bool TestStep(vector<vector<Cell>> Maze) {
		switch (DIRECTION) {
		case NORTH:
			return Maze[COORD.first - 1][COORD.second].IsFreee();
			break;
		case SOUTH:
			return Maze[COORD.first + 1][COORD.second].IsFreee();
			break;
		case WEST:
			return Maze[COORD.first][COORD.second - 1].IsFreee();
			break;
		case EAST:
			return Maze[COORD.first][COORD.second + 1].IsFreee();
			break;
		}


	}

	directions TestTunnel() {
		switch (DIRECTION) {
		case EAST:
			if (make_pair(COORD.first, COORD.second + 1) == make_pair(14.0f, 27.0f))
				return EAST;
			break;
		case WEST:
			if (make_pair(COORD.first, COORD.second - 1) == make_pair(14.0f, 0.0f))
				return WEST;
			break;
		default:
			return STOP;
		}

	}

public:

	GameMob(coordinates setCoordinates, directions setDirection) {
		COORD.first = setCoordinates.first;
		COORD.second = setCoordinates.second;
		DIRECTION = setDirection;
	}

	void ChangeDirection(directions newDirection) {
		DIRECTION = newDirection;
	}

	void Move(vector<vector<Cell>> Maze) {

		//ChangeDirection(newDirection);
		switch (TestTunnel()) {
		case WEST:
			COORD.second = 27.0f;
			return;
		case EAST:
			COORD.second = 0.0f;
			return;
		default:
			break;
		}


		switch (DIRECTION) {
		case NORTH:
			if (TestStep(Maze) == true)
				COORD.first -= 1;
			else
				DIRECTION = STOP;
			break;
		case SOUTH:
			if (TestStep(Maze) == true)
				COORD.first += 1;
			else
				DIRECTION = STOP;
			break;
		case WEST:
			if (TestStep(Maze) == true)
				COORD.second -= 1;
			else
				DIRECTION = STOP;
			break;
		case EAST:
			if (TestStep(Maze) == true)
				COORD.second += 1;
			else
				DIRECTION = STOP;
			break;
		}
	}

	coordinates& GetCOORD() {
		return COORD;
	}

	directions& GetDIRECTION() {
		return DIRECTION;
	}


};