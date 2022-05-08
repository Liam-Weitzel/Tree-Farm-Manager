#ifndef OLIVELIST_H
#define OLIVELIST_H
#include "PolyArea.h"
#include "Farm.h"
#include "Olive.h"

class OliveList
{
private:
	Olive list[30];

public:
	OliveList();
	Olive* getOlives();
};

#endif