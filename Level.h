#pragma once
#include "Header.h"
#include "Cell.h"
#include "PacMan.h"
#include "Ghost.h"

//Îñíîâíîé êëàññ

constexpr auto NUM_GHOSTS = 1;
constexpr auto NUM_OF_REGULAR_POINTS = 240;
constexpr auto NUM_OF_ENERGIZERS = 4;


class Level {

private:

	vector<vector<Cell>> Maze;

	vector <Ghost> aliveGhosts;

	queue <Ghost> deadGhosts;

	PacMan pacman;

	int countOfEatenGhosts;

	int levelStage;

	int countOfRegularPoints, countOfEnergizers;


public:

	Level() { countOfEatenGhosts = 0; levelStage = 1; 
	countOfRegularPoints = 0; countOfEnergizers = 0; }

	void InitLevel(ifstream& fileWithLevel) {

		string line;
		int i, j;

		fileWithLevel.seekg(0, ios::beg);


		for (i = 0; getline(fileWithLevel, line); i++) {
			Maze.push_back(vector<Cell>());
			for (j = 0; j < line.size(); j++) {
				switch (line[j]) {
				case int('#') :
					Maze[i].emplace_back(false, NONE, make_pair(i, j));
					break;

				case int('.') :
					Maze[i].emplace_back(true, REGULAR_POINT, make_pair(i, j));
					break;

				case int('$') :
					Maze[i].emplace_back(true, ENERGIZER, make_pair(i, j));
					break;

				default:
					Maze[i].emplace_back(true, NONE, make_pair(i, j));
					break;

				}
			}
		}

		for (i = 0; i < NUM_GHOSTS; i++) {
			aliveGhosts.emplace_back();
		}

	}

	void FindPacMan() {
		vector<int> rememberDeadGhosts;
		for (vector<Ghost>::iterator it = aliveGhosts.begin(); it < aliveGhosts.end();  it++) {
			it->FindPacMan(Maze, pacman);
			if (it->ActionWithGhost(pacman) == EAT) {
				pacman.GetPacmanLifes()--;
			}
			else if(it->ActionWithGhost(pacman) == BE_EATTEN){
				deadGhosts.push(*it);
				rememberDeadGhosts.push_back(it - aliveGhosts.begin());
			}
		}
		//Delete dead ghosts from vector of alive ghosts
		for (auto i : rememberDeadGhosts) {
			aliveGhosts.erase(aliveGhosts.begin() + i);
		}


	}

	void EatScores(ifstream& fileWithLevel) {
		switch (Maze[pacman.GetCOORD().first][pacman.GetCOORD().second].WhatBonus()) {
		case REGULAR_POINT:
			Maze[pacman.GetCOORD().first][pacman.GetCOORD().second].WhatBonus() = NONE;
			pacman.GetScores() += 10;
			countOfRegularPoints++;
			break;

		case ENERGIZER:
			Maze[pacman.GetCOORD().first][pacman.GetCOORD().second].WhatBonus() = NONE;
			pacman.GetScores() += 50;
			countOfEnergizers++;
			for (auto& ghost: aliveGhosts) {
				ghost.ChangeStatus(FRIGHTENED);
			}
			break;
			
		case NONE:
			break;
		}

		//Åñëè âñå ñúåäåíî, íà÷àòü íîâûé óðîâåíü
		if (countOfRegularPoints == NUM_OF_REGULAR_POINTS && countOfEnergizers == NUM_OF_ENERGIZERS) {
			StartNewLevel(fileWithLevel);
		}


	}

	PacMan& GetPacman() {
		return pacman;
	}

	vector<vector<Cell>> GetMaze() {
		return Maze;
	}

	vector <Ghost>& GetAliveGhosts() {
		return aliveGhosts;
	}

};
