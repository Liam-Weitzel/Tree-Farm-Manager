#ifndef CONSTRUCTIONLIST_H
#define CONSTRUCTIONLIST_H
#include "PolyArea.h"
#include "Construction.h"

class ConstructionList
{
private:
	Construction list[30];

public:
	ConstructionList();
	Construction* getConstructions();
};

#endif