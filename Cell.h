#pragma once
#include "Header.h"

enum bonuses {
	REGULAR_POINT,    //Обычная точка
	ENERGIZER,
	FRUIT
};

//Класс клетки, хранит информацию о "проходимости" клетки, и какой бонус на ней лежит

class Cell {

private:

	bool free;

	//Лежит ли на этой клетке какой-то бонус и какой бонус
	bonuses BONUS;


public:

};


