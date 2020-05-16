#include "stdafx.h"
#include "Level.h"

GAME_STATUS currGameStatus = BEGIN;

Level::Level() {
	doubleGhostScores = 1;
	levelStage = 1;
	pacmanLifes = 4;
	countOfEatenRegularPoints = 0;
	countOfEatenEnergizers = 0;
	countOfEatenFruits = 0;
	scores = 0;
}

void Level::DeleteAllGhosts() {
	aliveGhosts.clear();
	deadGhosts.clear();
}

void Level::PlaceInGhosts() {
	for (int i = 0; i < NUM_GHOSTS; i++) {
		aliveGhosts.emplace_back();
	}
}

void Level::StartNewLevel() {
	DeleteAllGhosts();
	curMaze.clear();
	doubleGhostScores = 1;
	countOfEatenRegularPoints = 0;
	countOfEatenEnergizers = 0;
	levelStage++;
	currGameStatus = BEGIN;

	curMaze = backUpMaze;
	PlaceInGhosts();
	pacman.RespawnPacMan();
}

//When pacman dies
void Level::StartNewGame() {
	DeleteAllGhosts();
	curMaze.clear();
	doubleGhostScores = 1;
	countOfEatenRegularPoints = 0;
	countOfEatenEnergizers = 0;
	countOfEatenFruits = 0;
	levelStage = 1;
	currGameStatus = BEGIN;

	pacmanLifes = PACMAN_LIFES;
	scores = 0;

	curMaze = backUpMaze;
	PlaceInGhosts();
	pacman.RespawnPacMan();
}

void Level::GhostsActions() {
	vector<int> rememberDeadGhosts;
	for (vector<Ghost>::iterator it = aliveGhosts.begin(); it < aliveGhosts.end(); it++) {
		switch (it->Move(curMaze, pacman)) {
		case EAT:
			if (--pacmanLifes == 0) {
				StartNewGame();
				return;
			}
			else {
				SetPacmanDeath();
				return;
			}
			break;
		case BE_EATTEN:
			it->SetGhostDeath();
			deadGhosts.push_back(*it);
			rememberDeadGhosts.push_back(it - aliveGhosts.begin());
			scores += 200 * doubleGhostScores;
			doubleGhostScores += 2;
			break;
		}
	}

	//Delete dead ghosts from vector of alive ghosts
	for (auto i : rememberDeadGhosts) {
		aliveGhosts.erase(aliveGhosts.begin() + i);
	}

}

void Level::PacManAction() {
	switch (pacman.Action(curMaze)) {
	case REGULAR_POINT:
		curMaze[pacman.GetCoord().first][pacman.GetCoord().second].ChangBonus(NONE);
		scores += 10;
		countOfEatenRegularPoints++;
		break;
	case ENERGIZER:
		curMaze[pacman.GetCoord().first][pacman.GetCoord().second].ChangBonus(NONE);
		scores += 50;
		countOfEatenEnergizers++;
		for (auto& ghost : aliveGhosts) {
			ghost.ChangeStatus(FRIGHTENED);
		}
		break;
	}

	//If all scores have eatten, start new level
	if (countOfEatenRegularPoints == NUM_OF_REGULAR_POINTS && countOfEatenEnergizers == NUM_OF_ENERGIZERS) {
		StartNewLevel();
	}
}

void Level::SetPacmanDeath() {
	DeleteAllGhosts();
	PlaceInGhosts();
	pacman.RespawnPacMan();
}

void Level::ChangeGhostsStatus(status_name setStatus) {
	for (auto& ghost : aliveGhosts) {
		ghost.ChangeStatus(setStatus);
	}
}

void Level::InitLevel(ifstream& fileWithLevel) {

	string line;
	int i, j;

	for (i = 0; getline(fileWithLevel, line); i++) {
		curMaze.push_back(vector<Cell>());
		backUpMaze.push_back(vector<Cell>());
		for (j = 0; j < line.size(); j++) {
			switch (line[j]) {
			case int('#') :
				curMaze[i].emplace_back(false, NONE, make_pair(i, j));
				backUpMaze[i].emplace_back(false, NONE, make_pair(i, j));
				break;

			case int('.') :
				curMaze[i].emplace_back(true, REGULAR_POINT, make_pair(i, j));
				backUpMaze[i].emplace_back(true, REGULAR_POINT, make_pair(i, j));
				break;

			case int('$') :
				curMaze[i].emplace_back(true, ENERGIZER, make_pair(i, j));
				backUpMaze[i].emplace_back(true, ENERGIZER, make_pair(i, j));
				break;

			default:
				curMaze[i].emplace_back(true, NONE, make_pair(i, j));
				backUpMaze[i].emplace_back(true, NONE, make_pair(i, j));
				break;

			}
		}
	}
	PlaceInGhosts();
}

void Level::TimerFunction() {

	for (auto& ghost : aliveGhosts) {
		ghost.ChangeFunction();
		ghost.GetOutOfBox();
	}
}

void Level::Play() {
	TimerFunction();
	PacManAction();
	GhostsActions();
}

