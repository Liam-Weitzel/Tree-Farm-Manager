#ifndef FARMLIST_H
#define FARMLIST_H
#include "PolyArea.h"
#include "Farm.h"

class FarmList
{
private:
	Farm list[30];

public:
	FarmList();
	Farm* getFarms();
};

#endif