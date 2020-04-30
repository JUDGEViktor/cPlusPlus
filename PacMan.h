#pragma once
#include "Header.h"
#include "GameMob.h"

enum directions {
	NORTH,
	SOUTH,
	WEST,
	EAST
};

class PacMan : public GameMob {

private:

	directions DIRECT;

	void ChangeDirection(){}

	bool TestStep(){}

	void Move(){}

public:

	PacMan() : GameMob() {}

	void ActionWithGhost() {}

	void ActinoWithBonuses() {}

	void SpawnPacMan() {}

};
