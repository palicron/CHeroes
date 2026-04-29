#include "Weapon.h"

std::string Weapon::ToString() const
{
   return " " + Name + "  :" + std::to_string(Min_Damage) + "-" + std::to_string(Max_Damage) + " Damage";
}
