#pragma once
#include <string>
#include <vector>

#include "Types.h"

class Weapon
{
public:
    Weapon() = default;

    Weapon(std::string&& InName, int32_t InDamage, int32_t InMagicDamage, EWeaponClass InClass, std::vector<EDamageAttribute>&& InDamageAttributes) : Name(std::move(InName)), Damage(InDamage), MagicDamage(InMagicDamage),
                                                                                                                                                      WeaponClass(InClass), DamageAttributes(std::move(InDamageAttributes))
    {
    }
    
    Weapon(const Weapon& Other) = default;
    
    Weapon& operator=(const Weapon& Other) = default;
    
    Weapon(Weapon&& Other) noexcept = default;
    
    Weapon& operator=(Weapon&& Other) = default;
    
    ~Weapon() = default;
    
private:
    
    std::string Name;
    
    int32_t Damage;
    
    int32_t MagicDamage;
    
    EWeaponClass WeaponClass;
    
    std::vector<EDamageAttribute> DamageAttributes;
    
};
