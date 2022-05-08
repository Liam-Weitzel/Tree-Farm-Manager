#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "PolyArea.h"
#include "Farm.h"
#include "Orange.h"
#include "OrangeList.h"

OrangeList::OrangeList() {

}

Orange* OrangeList::getOranges() {
	return this->list;
}