#include "Warrior.h"

#include <algorithm>
#
void Warrior::MeleeAttack(Hero& Target)
{
	MeleeHero::MeleeAttack(Target);
	Resource = std::clamp(Resource + 4, 0, MaxResource);
}
