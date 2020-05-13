#pragma once
#include "Header.h"
#include "GameMob.h"
#include "PacMan.h"
#include "Cell.h"

enum status {
	REGULAR,
	FRIGHTENED,
	RELAX
};

enum action_with_pacman {
	EAT,
	BE_EATTEN
};

class Ghost : public GameMob {

private:

	status STATUS;
  
  float MinDistance(coordinates src, coordinates dst) {
		return (sqrt(pow(src.second - dst.second, 2) + pow(src.first - dst.first, 2)));
	}

	void FindWayToDestination(vector<vector<Cell>> Maze, coordinates destination) {}

public:

	Ghost() : GameMob(make_pair(13.0f, 14.0f), STOP) { 
		STATUS = REGULAR; 
		inBox = true;
	}
  
  void FindPacMan(vector<vector<Cell>> Maze, PacMan pacman) {
		FindWayToDestination(Maze, pacman.GetCOORD());
	}

	action_with_pacman ActionWithPacman(PacMan pacman) {}


};
