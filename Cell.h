#pragma once
#include "Libraries.h"

enum bonuses {
	REGULAR_POINT,    //Обычная точка
	ENERGIZER,
	FRUIT,
	NONE
};

//Класс клетки, хранит информацию о "проходимости" клетки, и какой бонус на ней лежит

class Cell {

private:

	bool free;

	//Лежит ли на этой клетке какой-то бонус и какой бонус
	bonuses bonus;

	coordinates coord;


public:

	Cell(bool setStatus, bonuses setBonus, coordinates setCoordinates) {
		free = setStatus;
		bonus = setBonus;

		coord = setCoordinates;
	}

	bool IsFreee() {
		return free;
	}

	bonuses WhatBonus() {
		return bonus;
	}

	coordinates GetCoord() {
		return coord;
	}

};


