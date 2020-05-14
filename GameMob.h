#pragma once
#include "Libraries.h"

enum directions {
	NORTH,
	SOUTH,
	WEST,
	EAST,
	STOP
};

class GameMob {

private:

	coordinates coord;

	directions direction;

	bool TestStep(vector<vector<Cell>> maze) {
		switch (direction) {
		case NORTH:
			return maze[coord.first - 1][coord.second].IsFreee();
			break;
		case SOUTH:
			return maze[coord.first + 1][coord.second].IsFreee();
			break;
		case WEST:
			return maze[coord.first][coord.second - 1].IsFreee();
			break;
		case EAST:
			return maze[coord.first][coord.second + 1].IsFreee();
			break;
		}


	}

	directions TestTunnel() {
		switch (direction) {
		case EAST:
			if (make_pair(coord.first, coord.second + 1) == make_pair(14.0f, 27.0f))
				return EAST;
			break;
		case WEST:
			if (make_pair(coord.first, coord.second - 1) == make_pair(14.0f, 0.0f))
				return WEST;
			break;
		default:
			return STOP;
		}

	}

public:

	GameMob(coordinates setCoordinates, directions setDirection) {
		coord.first = setCoordinates.first;
		coord.second = setCoordinates.second;
		direction = setDirection;
	}

	void ChangeDirection(directions newDirection) {
		direction = newDirection;
	}

	void Move(vector<vector<Cell>> maze) {

		switch (TestTunnel()) {
		case WEST:
			coord.second = 27.0f;
			return;
		case EAST:
			coord.second = 0.0f;
			return;
		default:
			break;
		}


		switch (direction) {
		case NORTH:
			if (TestStep(maze))
				coord.first -= 1;
			else
				direction = STOP;
			break;
		case SOUTH:
			if (TestStep(maze))
				coord.first += 1;
			else
				direction = STOP;
			break;
		case WEST:
			if (TestStep(maze))
				coord.second -= 1;
			else
				direction = STOP;
			break;
		case EAST:
			if (TestStep(maze))
				coord.second += 1;
			else
				direction = STOP;
			break;
		}
	}

	coordinates GetCoord() {
		return coord;
	}

	directions GetDirection() {
		return direction;
	}
	
	void ChangeCoord(coordinates setCoordinates) {
		coord = setCoordinates;
	}

	void ChangeDirection(directions setDirection) {
		direction = setDirection;
	}


};
