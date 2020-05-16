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

	Cell(bool setStatus, const bonuses& setBonus, const coordinates& setCoordinates);

	bool IsFreee() const {
		return free;
	}

	bonuses WhatBonus() const {
		return bonus;
	}

	void ChangBonus(bonuses setBonus) {
		bonus = setBonus;
	}

	coordinates GetCoord() const {
		return coord;
	}

};


