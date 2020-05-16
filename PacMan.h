#pragma once

#include "resource.h"
#include "Libraries.h"
#include "GameMob.h"
#include "Cell.h"


class PacMan : public GameMob {

private:

	bonuses EatScores(const Table& maze);

public:

	PacMan() : GameMob(make_pair(29.0, 12.0), STOP) {}

	//Need when pacman dies
	void RespawnPacMan();

	bonuses Action(const Table& maze);
	
};