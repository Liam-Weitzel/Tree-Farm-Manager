#ifndef AREALIST_H
#define AREALIST_H
#include "PolyArea.h"

class AreaList
{
private:
	PolyArea list[99];

public:
	AreaList();
	PolyArea* getAreas();
};

#endif