#pragma once
#include <string>

#include "Types.h"

class Ability
{
public:
    Ability(std::string inName , int32_t inDamage,int32_t inCooldown,int32_t inCost, EDamageAttribute inDamageAttribute,DamageType inType) : Name(inName), Cooldown(inCooldown), Cost(inCost),
        Damage(inDamage), LastCastTurn(0), Type(inType), DamageAttribute(inDamageAttribute)
    {
    }

    ~Ability() = default;
    
    bool CastAbility(Hero& Target, Hero& Caster,const int32_t CurrentTurn);
    
    
    int32_t GetCooldown() const { return Cooldown; }
    int32_t GetCost() const { return Cost; }
    std::string GetName() const { return Name; }
    int32_t GetDamage() const { return Damage; }
    EDamageAttribute GetDamageAttribute() const { return DamageAttribute; }
    

private:
    
    std::string Name;
    
    int32_t Cooldown;
    int32_t Cost;
    int32_t Damage;
    int32_t LastCastTurn;
    DamageType Type;
    EDamageAttribute DamageAttribute;
};
