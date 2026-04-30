#include "Barbarian.h"

#include <algorithm>

void Barbarian::TakeDamage(const DamageInfo& DamageInfo)
{
    MeleeHero::TakeDamage(DamageInfo);
    Resource = std::clamp(Resource + 15, 0, MaxResource);
}
