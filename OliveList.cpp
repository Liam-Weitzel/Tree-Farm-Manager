#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "PolyArea.h"
#include "Farm.h"
#include "Olive.h"
#include "OliveList.h"

OliveList::OliveList() {

}

Olive* OliveList::getOlives() {
	return this->list;
}