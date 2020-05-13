#pragma once

#include "resource.h"
#include "Header.h"
#include "GameMob.h"
#include "Cell.h"


class PacMan : public GameMob {

private:

	int pacmanLifes;

	int scores;


public:

	PacMan() : GameMob(make_pair(29.0, 12.0), STOP) { pacmanLifes = 4; scores = 0; }

	int& GetPacmanLifes() {
		return pacmanLifes;
	}

	int& GetScores() {
		return scores;
	}

	

};
