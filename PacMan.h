#pragma once

#include "resource.h"
#include "Header.h"
#include "GameMob.h"
#include "Cell.h"


class PacMan : public GameMob {

private:

	int pacmanLifes;

public:

	PacMan() : GameMob(make_pair(29.0, 12.0), STOP) { pacmanLifes = 4; }

	//Need when pacman dies
	void RespawnPacMan() {
		GetCOORD() = make_pair(29.0, 12.0);
		GetDIRECTION() = STOP;
	}
	
};
