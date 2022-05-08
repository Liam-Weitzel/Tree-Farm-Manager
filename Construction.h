#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H
#include <stdio.h>
#include "PolyArea.h"

class Construction :public PolyArea
{
private:
	std::string start_date;
	std::string end_date;
	std::string contractor;
public:
	Construction(PolyArea parent);
	Construction();
	void setStart(std::string start);
	void setEnd(std::string end);
	void setContractor(std::string contract);
	std::string getStart();
	std::string getEnd();
	std::string getContractor();
};

#endif