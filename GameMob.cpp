#include "stdafx.h"
#include "GameMob.h"


GameMob::GameMob(const coordinates& setCoordinates, const directions& setDirection) {
	coord.first = setCoordinates.first;
	coord.second = setCoordinates.second;
	direction = setDirection;
}

const bool GameMob::TestStep(const Table& maze) {
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


directions GameMob::TestTunnel() {
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


void GameMob::Move(const Table& maze) {

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