#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "PolyArea.h"
#include "Construction.h"
#include "ConstructionList.h"

ConstructionList::ConstructionList() {

}

Construction* ConstructionList::getConstructions() {
	return this->list;
}