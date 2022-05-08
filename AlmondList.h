#ifndef ALMONDLIST_H
#define ALMONDLIST_H
#include "PolyArea.h"
#include "Farm.h"
#include "Almond.h"

class AlmondList
{
private:
	Almond list[30];

public:
	AlmondList();
	Almond* getAlmonds();
};

#endif