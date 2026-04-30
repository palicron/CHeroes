#include "Weapon.h"

#include <random>

std::string Weapon::ToString() const
{
   return " " + Name + "  :" + std::to_string(Min_Damage) + "-" + std::to_string(Max_Damage) + " Damage";
}

int32_t Weapon::GetAttackDamage() const
{
   static std::random_device RD;
   static std::mt19937 Engine(RD());
   std::uniform_int_distribution<int32_t> Dist(Min_Damage, Max_Damage);

   return Dist(Engine);
}
