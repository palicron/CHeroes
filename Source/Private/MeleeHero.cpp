#include "MeleeHero.h"

#include <algorithm>

void MeleeHero::EndTurn()
{
    Resource = std::clamp(Resource - 3, 0, MaxResource);
}
