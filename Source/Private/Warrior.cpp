#include "Warrior.h"

#include <algorithm>
#
void Warrior::MeleeAttack(Hero& Target)
{
	MeleeHero::MeleeAttack(Target);
	Resource = std::clamp(Resource + 5, 0, MaxResource);
}
