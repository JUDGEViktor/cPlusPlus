#pragma once
#include "Header.h"
#include "Cell.h"
#include "PacMan.h"
#include "Ghost.h"

//����� ������� ����. �������� ������ ������ = ��������, ������ ���������� � ������ �������
//�������� ���������� � ������� ������� � ���������� �����, ��������, �-��� InterractWithPacMan / InterractWithGhost

class Level {

private:

	Cell Map[20][20];


public:

	Level() {}

	void GenerateBonuses() {}

};
