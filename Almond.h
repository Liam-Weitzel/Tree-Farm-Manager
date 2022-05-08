#ifndef ALMOND_H
#define ALMOND_H
#include <stdio.h>
#include "PolyArea.h"
#include "Farm.h"

class Almond :public Farm
{
private:
	std::string possiblespecies[3];
	int species;
public:
	Almond(Farm parent);
	Almond();
	int getSpecies();
	void setSpecies(int s);
	std::string* getPossibleSpecies();
	void setPossibleSpecies(std::string s);
};

#endif