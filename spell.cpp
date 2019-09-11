#include "spell.h"
#include "projectile.h"


spell::spell(std::string filename)
{
	name = "test";
	charname = "charname";
	type = "projectile";
}

bool spell::use(int x, int y)
{
}

spell::~spell()
{
}
