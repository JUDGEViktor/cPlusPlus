#pragma once
#include "Header.h"

enum bonuses {
	REGULAR_POINT,    //Обычная точка
	ENERGIZER,
	FRUIT
};

enum status {
	FREE, 
	NOT_FREE
};

//Класс клетки, хранит информацию о "проходимости" клетки, и какой бонус на ней лежит

class Cell {

private:

	status STATUS;

	//Лежит ли на этой клетке какой-то бонус и какой бонус
	bonuses BONUS;


public:
	
	Cell(status setStatus, bonuses setBonus) {
		STATUS = setStatus;
		BONUS = setBonus;
	}

};


