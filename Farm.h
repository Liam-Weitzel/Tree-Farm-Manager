#ifndef FARM_H
#define FARM_H
#include <stdio.h>
#include "PolyArea.h"

class Farm:public PolyArea
{
private:
	std::string harvest_dates[99];
	float yield_kilos[99];
	std::string plant_dates[99];
	std::string plowing_dates[99];
	std::string milling_dates[99];
	std::string shredding_dates[99];
	std::string pruning_dates[99];
public:
	Farm(PolyArea parent);
	Farm();
	std::string* get_harvest();
	float* get_yield();
	std::string* get_plant();
	std::string* get_plowing();
	std::string* get_milling();
	std::string* get_shredding();
	std::string* get_pruning();
	void set_harvest(std::string h);
	void set_yield(float y);
	void set_plant(std::string p);
	void set_plowing(std::string p2);
	void set_milling(std::string m);
	void set_shredding(std::string s);
	void set_pruning(std::string p3);
};

#endif