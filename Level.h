#pragma once
#include "Header.h"
#include "Cell.h"
#include "PacMan.h"
#include "Ghost.h"

// Class of levels. Include mass of cells = labyrinth
// Methods: generate bonuses, I think that's all for now.

class Level {

private:

	Cvector<vector<Cell>> Map;


public:

	Level() {}

	void GenerateBonuses() {}

};
