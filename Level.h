#pragma once
#include "Header.h"
#include "Cell.h"
#include "PacMan.h"
#include "Ghost.h"

//Класс уровней игры. Содержит массив клеток = лабиринт, вектор приведений и самого пакмена
//Планирую обращаться к методам пакмена и приведений через, например, ф-ции InterractWithPacMan / InterractWithGhost

class Level {

private:

	Cell Map[20][20];


public:

	Level() {}

	void GenerateBonuses() {}

};
