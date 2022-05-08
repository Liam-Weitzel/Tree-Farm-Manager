#ifndef FARM_H
#define FARM_H
#include <stdio.h>
#include "PolyArea.h"

class Farm:public PolyArea
{
private:
	char** harvest_dates;
	float yield_kilos[99];
	char** plant_dates;
	char** plowing_dates;
	char** milling_dates;
	char** shredding_dates;
	char** pruning_dates;
public:
	Farm(PolyArea parent);
	Farm();
	char** get_harvest();
	float* get_yield();
	char** get_plant();
	char** get_plowing();
	char** get_milling();
	char** get_shredding();
	char** get_pruning();
	void set_harvest(char** h);
	void set_yield(float y[]);
	void set_plant(char** p);
	void set_plowing(char** p2);
	void set_milling(char** m);
	void set_shredding(char** s);
	void set_pruning(char** p3);
	void set_next_harvest(char* h);
	void set_next_yield(float y);
	void set_next_plant(char* p);
	void set_next_plowing(char* p2);
	void set_next_milling(char* m);
	void set_next_shredding(char* s);
	void set_next_pruning(char* p3);
};

#endif