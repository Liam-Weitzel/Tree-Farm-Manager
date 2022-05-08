#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
#include "PolyArea.h"
#include "Construction.h"

Construction::Construction(PolyArea parent) {
	this->setLineX(parent.getLineX());
	this->setLineY(parent.getLineY());
	this->setDotX(parent.getDotX());
	this->setDotY(parent.getDotY());
	this->setI(parent.getI());
	this->setFirstDot(parent.getFirstDotX(), parent.getFirstDotY());
	this->setRGBO((GLfloat)parent.getRGBO().x, (GLfloat)parent.getRGBO().y, (GLfloat)parent.getRGBO().z, (GLfloat)parent.getRGBO().w);
}

Construction::Construction() {
}

void Construction::setStart(std::string start) {
	this->start_date = start;
}

void Construction::setEnd(std::string end) {
	this->end_date = end;
}
void Construction::setContractor(std::string contract) {
	this->contractor = contract;
}
std::string Construction::getStart() {
	return this->start_date;
}
std::string Construction::getEnd() {
	return this->end_date;
}
std::string Construction::getContractor() {
	return this->contractor;
}