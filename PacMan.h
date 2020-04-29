#pragma once
#include "Header.h"
#include "GameMob.h"


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