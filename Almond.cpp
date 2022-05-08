#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
#include "PolyArea.h"
#include "Farm.h"
#include "Almond.h"

Almond::Almond(Farm parent) {
	this->setLineX(parent.getLineX());
	this->setLineY(parent.getLineY());
	this->setDotX(parent.getDotX());
	this->setDotY(parent.getDotY());
	this->setI(parent.getI());
	this->setFirstDot(parent.getFirstDotX(), parent.getFirstDotY());
	this->setRGBO((GLfloat)parent.getRGBO().x, (GLfloat)parent.getRGBO().y, (GLfloat)parent.getRGBO().z, (GLfloat)parent.getRGBO().w);
	this->set_harvest(parent.get_harvest());
	this->set_yield(parent.get_yield());
	this->set_plant(parent.get_plant());
	this->set_plowing(parent.get_plowing());
	this->set_milling(parent.get_milling());
	this->set_shredding(parent.get_shredding());
	this->set_pruning(parent.get_pruning());
	this->possiblespecies[0] = "Nelpus";
	this->possiblespecies[1] = "Butte";
	this->possiblespecies[2] = "Bitter";
}
Almond::Almond() {
}
int Almond::getSpecies() {
	return this->species;
}
void Almond::setSpecies(int s) {
	this->species = s;
}
std::string* Almond::getPossibleSpecies() {
	return this->possiblespecies;
}
void Almond::setPossibleSpecies(std::string s) {
	this->possiblespecies[sizeof(possiblespecies - 1)] = s;
}