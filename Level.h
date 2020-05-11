#pragma once
#include "Header.h"
#include "Cell.h"
#include "PacMan.h"
#include "Ghost.h"

//Основной класс

#define NUM_GHOSTS 4

enum GAME_STATUS {
	BEGIN,
	PLAY,
	DEATH,
	NEXT_LEVEL,
	END
};
GAME_STATUS currGameStatus = BEGIN;


class Level {

private:

	vector<vector<Cell>> Maze;
	float LENGTH;
	float HEIGHT;

	vector <Ghost> aliveGhosts;

	queue <Ghost> deadGhosts;

	PacMan pacman;

	int pacmanLifes = 4;

	int countOfEatenGhosts;

public:

	void InitLevel(ifstream& fileWithLevel) {

		string line;
		int i, j;

		for (i = 0; getline(fileWithLevel, line); i++) {
			Maze.push_back(vector<Cell>());
			for (j = 0; j < line.size(); j++) {
				switch (line[j]) {
				case int('#') :
					Maze[i].emplace_back(false, NONE, make_pair(SQUARE_SIZE*j, SQUARE_SIZE*i));
					break;

				case int('.') :
					Maze[i].emplace_back(true, REGULAR_POINT, make_pair(SQUARE_SIZE*j, SQUARE_SIZE*i));
					break;

				case int('$') :
					Maze[i].emplace_back(true, ENERGIZER, make_pair(SQUARE_SIZE*j, SQUARE_SIZE*i));
					break;

				default:
					Maze[i].emplace_back(true, NONE, make_pair(SQUARE_SIZE*j, SQUARE_SIZE*i));
					break;

				}
			}
		}

		LENGTH = SQUARE_SIZE * j;
		HEIGHT = SQUARE_SIZE * i;

	}


	void Play() {

		switch (currGameStatus) {
		case BEGIN:
			pacman.SpawnPacMan();
			for (int i = 0; i < NUM_GHOSTS; i++) {
				aliveGhosts.emplace_back();
			}
			currGameStatus = PLAY;
			break;

		case PLAY:
			break;

		case DEATH:
			break;

		case NEXT_LEVEL:
			break;

		case END:
			break;

		}


	}

};
