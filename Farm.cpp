#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
#include "PolyArea.h"
#include "Farm.h"

Farm::Farm(PolyArea parent) {
	this->setLineX(parent.getLineX());
	this->setLineY(parent.getLineY());
	this->setDotX(parent.getDotX());
	this->setDotY(parent.getDotY());
	this->setI(parent.getI());
	this->setFirstDot(parent.getFirstDotX(), parent.getFirstDotY());
	this->setRGBO((GLfloat)parent.getRGBO().x, (GLfloat)parent.getRGBO().y, (GLfloat)parent.getRGBO().z, (GLfloat)parent.getRGBO().w);
}

Farm::Farm() {
}

std::string* Farm::get_harvest() {
	return this->harvest_dates;
}
float* Farm::get_yield() {
	return this->yield_kilos;
}
std::string* Farm::get_plant() {
	return this->plant_dates;
}
std::string* Farm::get_plowing() {
	return this->plowing_dates;
}
std::string* Farm::get_milling() {
	return this->milling_dates;
}
std::string* Farm::get_shredding() {
	return this->shredding_dates;
}
std::string* Farm::get_pruning() {
	return this->pruning_dates;
}
void Farm::set_harvest(std::string h) {
	this->harvest_dates[sizeof(harvest_dates - 1)] = h;
}
void Farm::set_yield(float y) {
	this->yield_kilos[sizeof(yield_kilos - 1)] = y;
}
void Farm::set_plant(std::string p) {
	this->plant_dates[sizeof(plant_dates - 1)] = p;
}
void Farm::set_plowing(std::string p2) {
	this->plowing_dates[sizeof(plowing_dates - 1)] = p2;
}
void Farm::set_milling(std::string m) {
	this->milling_dates[sizeof(milling_dates - 1)] = m;
}
void Farm::set_shredding(std::string s) {
	this->shredding_dates[sizeof(shredding_dates - 1)] = s;
}
void Farm::set_pruning(std::string p3) {
	this->pruning_dates[sizeof(pruning_dates - 1)] = p3;
}