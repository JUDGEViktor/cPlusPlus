#pragma once
#include"Libraries.h"
#include"Level.h"

#define SQUARE_SIZE 20


void DrawMaze(HDC hdc, Table curMaze) {

	float sideLength = 4;
	HBRUSH hBrush; //создаём объект-кисть
	int quaterOfCell = SQUARE_SIZE / 4;
	int partOfCell = SQUARE_SIZE / 2;

	for (auto line : curMaze) {
		for (auto column : line) {

			if (column.IsFreee()) {

				hBrush = CreateSolidBrush(RGB(255, 0, 67)); //задаём сплошную кисть, закрашенную цветом RGB
				SelectObject(hdc, hBrush); //делаем кисть активной
				Rectangle(hdc, column.GetCoord().second * SQUARE_SIZE, column.GetCoord().first * SQUARE_SIZE,
					column.GetCoord().second * SQUARE_SIZE + SQUARE_SIZE, column.GetCoord().first * SQUARE_SIZE + SQUARE_SIZE);
				DeleteObject(hBrush);

				switch (column.WhatBonus()) {

				case REGULAR_POINT:
					hBrush = CreateSolidBrush(RGB(193, 0, 32)); //задаём сплошную кисть, закрашенную цветом RGB
					SelectObject(hdc, hBrush); //делаем кисть активной
					Ellipse(hdc, column.GetCoord().second * SQUARE_SIZE + quaterOfCell, column.GetCoord().first * SQUARE_SIZE + quaterOfCell,
						column.GetCoord().second * SQUARE_SIZE + SQUARE_SIZE - quaterOfCell, column.GetCoord().first * SQUARE_SIZE + SQUARE_SIZE - quaterOfCell);
					DeleteObject(hBrush);
					break;

				case ENERGIZER:
					hBrush = CreateSolidBrush(RGB(0, 107, 60)); //задаём сплошную кисть, закрашенную цветом RGB
					SelectObject(hdc, hBrush); //делаем кисть активной
					Ellipse(hdc, column.GetCoord().second * SQUARE_SIZE, column.GetCoord().first * SQUARE_SIZE,
						column.GetCoord().second * SQUARE_SIZE + SQUARE_SIZE, column.GetCoord().first * SQUARE_SIZE + SQUARE_SIZE);
					DeleteObject(hBrush);
					break;

				case NONE:
					break;

				}

			}

			else {
				hBrush = CreateSolidBrush(RGB(255, 255, 67)); //задаём сплошную кисть, закрашенную цветом RGB
				SelectObject(hdc, hBrush); //делаем кисть активной
				Rectangle(hdc, column.GetCoord().second * SQUARE_SIZE, column.GetCoord().first * SQUARE_SIZE,
					column.GetCoord().second * SQUARE_SIZE + SQUARE_SIZE, column.GetCoord().first * SQUARE_SIZE + SQUARE_SIZE);
				DeleteObject(hBrush);

			}

		}

	}

}

void DrawPacMan(HDC hdc, PacMan pacman) {
	HBRUSH hBrush; //создаём объект-кисть
	hBrush = CreateSolidBrush(RGB(255, 255, 0)); //задаём сплошную кисть, закрашенную цветом RGB
	Ellipse(hdc, pacman.GetCoord().second * SQUARE_SIZE, pacman.GetCoord().first * SQUARE_SIZE,
		pacman.GetCoord().second * SQUARE_SIZE + SQUARE_SIZE, pacman.GetCoord().first * SQUARE_SIZE + SQUARE_SIZE);
	DeleteObject(hBrush);
}

void DrawAliveGhost(HDC hdc, Level level) {
	HBRUSH hBrush; //создаём объект-кисть
	hBrush = CreateSolidBrush(RGB(139, 0, 255)); //задаём сплошную кисть, закрашенную цветом RGB
	for (auto ghost : level.GetAliveGhosts()) {
		Ellipse(hdc, ghost.GetCoord().second * SQUARE_SIZE, ghost.GetCoord().first * SQUARE_SIZE,
			ghost.GetCoord().second * SQUARE_SIZE + SQUARE_SIZE, ghost.GetCoord().first * SQUARE_SIZE + SQUARE_SIZE);
	}
	DeleteObject(hBrush);
}

void DrawDeadGhost(HDC hdc, Level level) {
	HBRUSH hBrush; //создаём объект-кисть
	hBrush = CreateSolidBrush(RGB(139, 0, 255)); //задаём сплошную кисть, закрашенную цветом RGB
	for (auto ghost : level.GetDeadGhosts()) {
		Ellipse(hdc, ghost.GetCoord().second * SQUARE_SIZE, ghost.GetCoord().first * SQUARE_SIZE,
			ghost.GetCoord().second * SQUARE_SIZE + SQUARE_SIZE, ghost.GetCoord().first * SQUARE_SIZE + SQUARE_SIZE);
	}
	DeleteObject(hBrush);
}

void DrawGhosts(HDC hdc, Level level) {
	DrawAliveGhost(hdc, level);
	DrawDeadGhost(hdc, level);
}

void DrawLifes(HDC hdc, Level level) {

	char numOfLifes[50] = { '\0' };
	char text[50] = "Lifes: ";
	_itoa_s(level.GetPacmanLifes(), numOfLifes, 10);
	strcat_s(text, numOfLifes);

	TextOutA(hdc, 30.0 * SQUARE_SIZE, 0.0 * SQUARE_SIZE, text, strlen(text));

}

void DrawScores(HDC hdc, PacMan pacman, Level level) {

	char numOfLifes[50] = { '\0' };//можно ещё обнулить, для уверенности
	char text[50] = "Scores: ";
	_itoa_s(level.GetScores(), numOfLifes, 10);//переводим число в строку
	strcat_s(text, numOfLifes);

	TextOutA(hdc, 30.0 * SQUARE_SIZE, 2.0 * SQUARE_SIZE, text, strlen(text));

}


void Display(HDC hdc, Level level) {
	DrawMaze(hdc, level.GetMaze());
	DrawPacMan(hdc, level.GetPacman());
	DrawGhosts(hdc, level);
	DrawLifes(hdc, level);
	DrawScores(hdc, level.GetPacman(), level);
}







