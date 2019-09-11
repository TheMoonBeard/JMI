#include <iostream>
#include "projectile.h"

class spell
{
public:
	spell(std::string filename);
	bool use(int x, int y);
	~spell();

private:
	std::string name;
	std::string charname;
	std::string type;
};
