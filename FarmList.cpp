#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "PolyArea.h"
#include "Farm.h"
#include "FarmList.h"

FarmList::FarmList() {

}

Farm* FarmList::getFarms() {
	return this->list;
}