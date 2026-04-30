#include "../Public/Caster.h"

#include <algorithm>

void Caster::EndTurn()
{
    Resource = std::clamp(Resource + (5 + (Intelligence/10) ), 0, MaxResource);
}
