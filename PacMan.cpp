#include "stdafx.h"
#include "PacMan.h"

bonuses PacMan::EatScores(const Table& maze) {
	switch (maze[GetCoord().first][GetCoord().second].WhatBonus()) {
	case REGULAR_POINT:
		return REGULAR_POINT;
		break;

	case ENERGIZER:
		return ENERGIZER;
		break;

	case NONE:
		break;
	}
}

void PacMan::RespawnPacMan() {
	ChangeCoord(make_pair(29.0, 12.0));
	ChangeDirection(STOP);
}

bonuses PacMan::Action(const Table& maze) {
	Move(maze);
	return EatScores(maze);
}