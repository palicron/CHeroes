#include "Barbarian.h"

#include <algorithm>

void Barbarian::TakeDamage(const DamageInfo& DamageInfo)
{
    MeleeHero::TakeDamage(DamageInfo);
    Resource = std::clamp(Resource + (DamageInfo.Amount / MaxResource * 15), 0, MaxResource);
}
