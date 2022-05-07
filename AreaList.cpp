#define _CRT_SECURE_NO_DEPRECATE
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <SOIL/SOIL.h>
#include "PolyArea.h"
#include "AreaList.h"

AreaList::AreaList() {
}

PolyArea* AreaList::getAreas() {
	return this->list;
}