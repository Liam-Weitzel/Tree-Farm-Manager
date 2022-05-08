#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "PolyArea.h"
#include "Farm.h"
#include "Almond.h"
#include "AlmondList.h"

AlmondList::AlmondList() {

}

Almond* AlmondList::getAlmonds() {
	return this->list;
}