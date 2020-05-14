#pragma once
#include "Libraries.h"
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

	status status;
  
	float MinDistance(coordinates src, coordinates dst) {
		return (sqrt(pow(src.second - dst.second, 2) + pow(src.first - dst.first, 2))); }

	void FindWayToDestination(vector<vector<Cell>> maze, coordinates destination) {}

public:

	Ghost() : GameMob(make_pair(13.0f, 14.0f), STOP) { 
		status = REGULAR; 
		inBox = true;
	}
  
	void FindPacMan(vector<vector<Cell>> maze, PacMan pacman) {
		FindWayToDestination(maze, pacman.GetCoord()); }

	action_with_pacman ActionWithPacman(PacMan pacman) {}


};
