#pragma once
#include "Header.h"
#include "GameMob.h"


class Ghost : public GameMob {

private:


public:

	//ф-ция, реализующая алгоритм A* для поиска пакмена
	//Искать пакмена приведения будут не больше 15 клеток
	//Если пакмена находится от приведения на расстоянии больше чем 2 клетки и приведение искало пакмена уже 15 клеток
	//то приведение начинает искать случайную точку в лабиринте 5 ходов
	vector<coordinates> FindWay() {}

	Ghost() : GameMob() {}

	void SpawnGhost() {}

};
