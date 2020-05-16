#pragma once
#include "Libraries.h"
#include "Cell.h"

using Table = vector<vector<Cell>>;

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

	const bool TestStep(const Table& maze);

	directions TestTunnel();

public:

	GameMob(const coordinates& setCoordinates, const directions& setDirection);

	void Move(const Table& maze);

	coordinates GetCoord() const{
		return coord;
	}

	directions GetDirection() const{
		return direction;
	}

	void ChangeCoord(const coordinates& setCoordinates) {
		coord = setCoordinates;
	}

	void ChangeDirection(const directions& setDirection) {
		direction = setDirection;
	}


};