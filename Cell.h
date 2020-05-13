#pragma once
#include "Header.h"

enum bonuses {
	REGULAR_POINT,    //Обычная точка
	ENERGIZER,
	FRUIT,
	NONE
};

//Класс клетки, хранит информацию о "проходимости" клетки, и какой бонус на ней лежит

class Cell {

private:

	bool FREE;

	//Лежит ли на этой клетке какой-то бонус и какой бонус
	bonuses BONUS;

	coordinates COORD;


public:

	Cell(bool setStatus, bonuses setBonus, coordinates setCoordinates) {
		FREE = setStatus;
		BONUS = setBonus;

		COORD.first = setCoordinates.first;
		COORD.second = setCoordinates.second;
	}

	bool IsFreee() {
		return FREE;
	}

	bonuses& WhatBonus() {
		return BONUS;
	}

	coordinates GetCOORD() {
		return COORD;
	}

};


