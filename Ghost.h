#pragma once
#include "Header.h"
#include "GameMob.h"


class Ghost : public GameMob {

private:


public:

	//�-���, ����������� �������� A* ��� ������ �������
	//������ ������� ���������� ����� �� ������ 15 ������
	//���� ������� ��������� �� ���������� �� ���������� ������ ��� 2 ������ � ���������� ������ ������� ��� 15 ������
	//�� ���������� �������� ������ ��������� ����� � ��������� 5 �����
	vector<coordinates> FindWay() {}

	Ghost() : GameMob() {}

	void SpawnGhost() {}

};
