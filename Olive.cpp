#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
#include "PolyArea.h"
#include "Farm.h"
#include "Olive.h"

Olive::Olive(Farm parent) {
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
	this->possiblespecies[0] = "Moresca";
	this->possiblespecies[1] = "Tonda Iblea";
	this->possiblespecies[2] = "O. europaea";
}
Olive::Olive() {
}
int Olive::getSpecies() {
	return this->species;
}
void Olive::setSpecies(int s) {
	this->species = s;
}
std::string* Olive::getPossibleSpecies() {
	return this->possiblespecies;
}
std::string* Olive::getDisenfection() {
	return this->disenfection_dates;
}
std::string* Olive::getFertilize() {
	return this->fertilize_dates;
}
void Olive::setFertilize(std::string f) {
	this->fertilize_dates[sizeof(fertilize_dates - 1)] = f;
}
void Olive::setPossibleSpecies(std::string s) {
	this->possiblespecies[sizeof(possiblespecies - 1)] = s;
}
void Olive::setDisenfection(std::string d) {
	this->disenfection_dates[sizeof(disenfection_dates - 1)] = d;
}