#pragma once
#include "Header.h"
#include "GameMob.h"
#include "PacMan.h"
#include "Cell.h"

enum status {
	REGULAR,
	FRIGHTENED
};

enum action_with_ghost {
	EAT,
	BE_EATTEN,
	NOTHING
};

class Ghost : public GameMob {

private:

	status STATUS;

	float MinDistance(coordinates src, coordinates dst) {
		return (sqrt(pow(src.second - dst.second, 2) + pow(src.first - dst.first, 2)));
	}

public:

	Ghost() : GameMob(make_pair(11.0, 15.0), STOP) { STATUS = REGULAR; }

	/*void SetGhost() {
		SetCOORD(make_pair(15.0 * SQUARE_SIZE, 15.0 * SQUARE_SIZE));
	}*/

	void FindPacMan(vector<vector<Cell>> Maze, PacMan pacman) {

		//Check north
		if (MinDistance(make_pair(GetCOORD().first - 1, GetCOORD().second), pacman.GetCOORD()) < MinDistance(GetCOORD(), pacman.GetCOORD())
			&& Maze[GetCOORD().first - 1][GetCOORD().second].IsFreee() && GetDIRECTION() != SOUTH) {
			GetCOORD() = make_pair(GetCOORD().first - 1, GetCOORD().second);
			ChangeDirection(NORTH);
			return;
		}

		//Check south
		if (MinDistance(make_pair(GetCOORD().first + 1, GetCOORD().second), pacman.GetCOORD()) < MinDistance(GetCOORD(), pacman.GetCOORD())
			&& Maze[GetCOORD().first + 1][GetCOORD().second].IsFreee() && GetDIRECTION() != NORTH) {
			GetCOORD() = make_pair(GetCOORD().first + 1, GetCOORD().second);
			ChangeDirection(SOUTH);
			return;
		}

		//Check west
		if (MinDistance(make_pair(GetCOORD().first, GetCOORD().second - 1), pacman.GetCOORD()) < MinDistance(GetCOORD(), pacman.GetCOORD())
			&& Maze[GetCOORD().first][GetCOORD().second - 1].IsFreee() && GetDIRECTION() != EAST) {
			GetCOORD() = make_pair(GetCOORD().first, GetCOORD().second - 1);
			ChangeDirection(WEST);
			return;
		}

		//Check east
		if (MinDistance(make_pair(GetCOORD().first, GetCOORD().second + 1), pacman.GetCOORD()) < MinDistance(GetCOORD(), pacman.GetCOORD())
			&& Maze[GetCOORD().first][GetCOORD().second + 1].IsFreee() && GetDIRECTION() != WEST) {
			GetCOORD() = make_pair(GetCOORD().first, GetCOORD().second + 1);
			ChangeDirection(EAST);
			return;
		}
		
		Move(Maze);

	}


	void ChangeStatus(status setStatus) {
		STATUS = setStatus;
	}

};
