#include "stdafx.h"
#include "Ghost.h"

void Ghost::FindWayToDestination(const Table& maze, const coordinates& destination) {

	//Check north
	if (MinDistance(make_pair(GetCoord().first - 1, GetCoord().second), destination) < MinDistance(GetCoord(), destination)
		&& maze[GetCoord().first - 1][GetCoord().second].IsFreee() && GetDirection() != SOUTH) {
		ChangeCoord(make_pair(GetCoord().first - 1, GetCoord().second));
		ChangeDirection(NORTH);
		return;
	}

	//Check south
	if (MinDistance(make_pair(GetCoord().first + 1, GetCoord().second), destination) < MinDistance(GetCoord(), destination)
		&& maze[GetCoord().first + 1][GetCoord().second].IsFreee() && GetDirection() != NORTH) {
		ChangeCoord(make_pair(GetCoord().first + 1, GetCoord().second));
		ChangeDirection(SOUTH);
		return;
	}

	//Check west
	if (MinDistance(make_pair(GetCoord().first, GetCoord().second - 1), destination) < MinDistance(GetCoord(), destination)
		&& maze[GetCoord().first][GetCoord().second - 1].IsFreee() && GetDirection() != EAST) {
		ChangeCoord(make_pair(GetCoord().first, GetCoord().second - 1));
		ChangeDirection(WEST);
		return;
	}

	//Check east
	if (MinDistance(make_pair(GetCoord().first, GetCoord().second + 1), destination) < MinDistance(GetCoord(), destination)
		&& maze[GetCoord().first][GetCoord().second + 1].IsFreee() && GetDirection() != WEST) {
		ChangeCoord(make_pair(GetCoord().first, GetCoord().second + 1));
		ChangeDirection(EAST);
		return;
	}

	GameMob::Move(maze);

}

action_with_pacman Ghost::FindPacMan(const Table& maze, PacMan& pacman) {
	FindWayToDestination(maze, pacman.GetCoord());
	return ActionWithPacman(pacman);
}

action_with_pacman Ghost::FindHome(const Table& maze, PacMan& pacman) {
	FindWayToDestination(maze, make_pair(1.0f, 27.0f));
	return ActionWithPacman(pacman);
}

action_with_pacman Ghost::ActionWithPacman(const PacMan& pacman) {

	if (GetCoord() == pacman.GetCoord()) {

		if (status == FRIGHTENED) {
			return BE_EATTEN;
		}

		if (status == REGULAR || status == RELAX) {
			return EAT;
		}

	}
}

void Ghost::GetOutOfBox() {
	if (inBox) {
		static int curTicks = 0;
		curTicks++;
		if (curTicks % RESPAWN_TIME == 0) {
			status = REGULAR;
			inBox = false;
			ChangeCoord(make_pair(11.0, 14.0));
			curTicks = 0;
			return;
		}
	}
	return;
}

void Ghost::ChangeFunction() {
	static int curTicks = 0;
	curTicks++;
	switch (status) {
	case FRIGHTENED:
		if (curTicks % FRIGHTENED_TIME == 0) {
			status = REGULAR;
			curTicks = 0;
			return;
		}
		break;
	case REGULAR:
		if (curTicks % REGULAR_TIME == 0) {
			status = RELAX;
			curTicks = 0;
			return;
		}
		break;
	case RELAX:
		if (curTicks % RELAX_TIME == 0) {
			status = REGULAR;
			curTicks = 0;
			return;
		}
		break;
	}
	return;
}

action_with_pacman Ghost::Move(const Table& maze, PacMan pacman) {

	if (status == FRIGHTENED || status == RELAX) {
		return(FindHome(maze, pacman));
	}

	else if (status == REGULAR) {
		return(FindPacMan(maze, pacman));
	}

}