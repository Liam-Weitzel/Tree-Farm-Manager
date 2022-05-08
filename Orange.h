#ifndef ORANGE_H
#define ORANGE_H
#include <stdio.h>
#include "PolyArea.h"
#include "Farm.h"

class Orange :public Farm
{
private:
	std::string possiblespecies[3];
	int species;
	std::string disenfection_dates[99];
	std::string fertilize_dates[99];
public:
	Orange(Farm parent);
	Orange();
	int getSpecies();
	void setSpecies(int s);
	std::string* getPossibleSpecies();
	std::string* getDisenfection();
	std::string* getFertilize();
	void setFertilize(std::string f);
	void setPossibleSpecies(std::string s);
	void setDisenfection(std::string d);
};

#endif