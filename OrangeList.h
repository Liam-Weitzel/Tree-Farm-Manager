#ifndef ORANGELIST_H
#define ORANGELIST_H
#include "PolyArea.h"
#include "Farm.h"
#include "Orange.h"

class OrangeList
{
private:
	Orange list[30];

public:
	OrangeList();
	Orange* getOranges();
};

#endif