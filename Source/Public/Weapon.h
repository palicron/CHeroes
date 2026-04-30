#pragma once
#include <string>
#include <vector>

#include "Types.h"

class Weapon
{
public:
    Weapon(): Min_Damage(0),Max_Damage(0), MagicDamage(0),WeaponClass(EWeaponClass_None)
    {
        
    }

    Weapon(std::string&& InName, int32_t InMinDamage, int32_t InMaxDamage,int32_t InMagicDamage, EWeaponClass InClass, std::vector<EDamageAttribute>&& InDamageAttributes) : Name(std::move(InName)), Min_Damage(InMinDamage),Max_Damage(InMaxDamage), MagicDamage(InMagicDamage),
                                                                                                                                                      WeaponClass(InClass), DamageAttributes(std::move(InDamageAttributes))
    {
    }
    
    Weapon(const Weapon& Other) = default;
    
    Weapon& operator=(const Weapon& Other) = default;
    
    Weapon(Weapon&& Other) noexcept = default;
    
    Weapon& operator=(Weapon&& Other) = default;
    
    ~Weapon() = default;
    
    virtual std::string ToString() const;
    
    int32_t GetAttackDamage() const;
    
    std::vector<EDamageAttribute> GetDamageAttributes() const
    {
        return DamageAttributes;
    }
    
    int32_t GetMagicDamage() const
    {
        return MagicDamage;
    }
private:
    
    std::string Name;
    
    int32_t Min_Damage;
    
    int32_t Max_Damage;
    
    int32_t MagicDamage;
    
    EWeaponClass WeaponClass;
    
    std::vector<EDamageAttribute> DamageAttributes;
    
};
