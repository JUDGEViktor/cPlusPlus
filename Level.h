#pragma once
#include "Header.h"
#include "Cell.h"
#include "PacMan.h"
#include "Ghost.h"

//Основной класс

constexpr auto NUM_GHOSTS = 4;
constexpr auto NUM_OF_REGULAR_POINTS = 240;
constexpr auto NUM_OF_ENERGIZERS = 4;


class Level {

private:

	int scores;

	vector<vector<Cell>> curMaze;
	vector<vector<Cell>> backUpMaze;

	vector <Ghost> aliveGhosts;

	queue <Ghost> deadGhosts;

	PacMan pacman;

	int countOfEatenGhosts;

	int levelStage;

	int countOfEatenRegularPoints, countOfEatenEnergizers, countOfEatenFruits;

	int gameThic;


public:

	Level() { 
		countOfEatenGhosts = 0; 
		levelStage = 1;
		countOfEatenRegularPoints = 0;
		countOfEatenEnergizers = 0;
		countOfEatenFruits = 0;
		scores = 0;
		gameThic = 1;
	}

	void InitLevel(ifstream& fileWithLevel) {

		string line;
		int i, j;

		fileWithLevel.seekg(0, ios::beg);


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

		for (i = 0; i < NUM_GHOSTS; i++) {
			aliveGhosts.emplace_back();
		}

	}

};
