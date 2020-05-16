#pragma once
#include "Libraries.h"
#include "Cell.h"
#include "PacMan.h"
#include "Ghost.h"


constexpr auto NUM_GHOSTS = 4;
constexpr auto NUM_OF_REGULAR_POINTS = 240;
constexpr auto NUM_OF_ENERGIZERS = 4;
constexpr auto PACMAN_LIFES = 4;

enum GAME_STATUS {
	BEGIN,
	PLAY,
	DEATH,
	NEXT_LEVEL,
	END
};


class Level {

private:

	int scores, pacmanLifes;

	Table curMaze;
	Table backUpMaze;

	vector <Ghost> aliveGhosts;
	vector <Ghost> deadGhosts;

	PacMan pacman;

	int doubleGhostScores;  //increase, when pacman eat ghost

	int levelStage;

	int countOfEatenRegularPoints, countOfEatenEnergizers, 
		countOfEatenFruits;

	void TimerFunction();

	void DeleteAllGhosts();

	void PlaceInGhosts();

	void StartNewLevel();

	//When pacman dies
	void SetPacmanDeath();

	void StartNewGame();

	void GhostsActions();

	void PacManAction();

	void ChangeGhostsStatus(status_name setStatus);


public:

	Level();

	void InitLevel(ifstream& fileWithLevel);

	void Play();

	void ChangePacmanDirection(const directions& setDirection) {
		pacman.ChangeDirection(setDirection);
	}

	/*----------------For Graphics-------------------*/
	const PacMan& GetPacman() {
		return pacman;
	}

	const Table& GetMaze() {
		return curMaze;
	}

	const vector<Ghost>& GetAliveGhosts() {
		return aliveGhosts;
	}

	const vector<Ghost> GetDeadGhosts() {
		return deadGhosts;
	}

	const int GetScores() {
		return scores;
	}

	const int GetPacmanLifes() {
		return pacmanLifes;
	}

};
