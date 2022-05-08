#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
#include "PolyArea.h"
#include "Farm.h"
#include "Orange.h"

Orange::Orange(Farm parent) {
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
	this->possiblespecies[0] = "Cara Cara";
	this->possiblespecies[1] = "Navel";
	this->possiblespecies[2] = "Blood";
}
Orange::Orange() {
}
int Orange::getSpecies() {
	return this->species;
}
void Orange::setSpecies(int s) {
	this->species = s;
}
std::string* Orange::getPossibleSpecies() {
	return this->possiblespecies;
}
std::string* Orange::getDisenfection() {
	return this->disenfection_dates;
}
std::string* Orange::getFertilize() {
	return this->fertilize_dates;
}
void Orange::setFertilize(std::string f) {
	this->fertilize_dates[sizeof(fertilize_dates - 1)] = f;
}
void Orange::setPossibleSpecies(std::string s) {
	this->possiblespecies[sizeof(possiblespecies - 1)] = s;
}
void Orange::setDisenfection(std::string d) {
	this->disenfection_dates[sizeof(disenfection_dates - 1)] = d;
}