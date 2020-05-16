#pragma once
#include "Libraries.h"
#include "GameMob.h"
#include "PacMan.h"
#include "Cell.h"

constexpr auto RESPAWN_TIME = 40;
constexpr auto FRIGHTENED_TIME = 15;
constexpr auto RELAX_TIME = 20;
constexpr auto REGULAR_TIME = 50;

enum status_name {
	REGULAR,
	FRIGHTENED,
	RELAX
};

enum action_with_pacman {
	EAT,
	BE_EATTEN,
	NOTHING
};

class Ghost : public GameMob {

private:

	status_name status;

	bool inBox;

	float MinDistance(const coordinates& src, const coordinates& dst) {
		return (sqrt(pow(src.second - dst.second, 2) + pow(src.first - dst.first, 2)));
	}

	void FindWayToDestination(const Table& maze, const coordinates& destination);

	action_with_pacman FindPacMan(const Table& maze, PacMan& pacman);

	action_with_pacman FindHome(const Table& maze, PacMan& pacman);

	action_with_pacman ActionWithPacman(const PacMan& pacman);

public:

	Ghost() : GameMob(make_pair(13.0f, 14.0f), STOP) { 
		status = REGULAR; 
		inBox = true;
	}

	//Use for get out of a box
	void GetOutOfBox();

	//For change ghost mood from frightened to relax and etc...
	void ChangeFunction();

	action_with_pacman Move(const Table& maze, PacMan pacman);

	void SetGhostDeath() {
		inBox = true;
		ChangeCoord(make_pair(13.0f, 14.0f));
	}

	void ChangeStatus(const status_name& setStatus) {
		status = setStatus;
	}

	const status_name GetStatus() {
		return status;
	}

	const bool InBox() {
		return inBox;
	}

	void ChangeInBoxStatus(bool setStatus) {
		inBox = setStatus;
	}

};
