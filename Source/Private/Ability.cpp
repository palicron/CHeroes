#include "../Public/Ability.h"

#include <iostream>

#include "../Public/Hero.h"

bool Ability::CastAbility(Hero& Target, Hero& Caster, const int32_t CurrentTurn)
{
    if (LastCastTurn >= 0 && (CurrentTurn - LastCastTurn) <= Cooldown )
    {
        std::cout << "====================================\n";
        std::cout << "IN Cd \n";
        std::cout << "====================================\n";
        return false;
    }
    
    if (Caster.GetResource() < Cost)
    {
        std::cout << "====================================\n";
        std::cout << "Not enough resources \n";
        std::cout << "====================================\n";
        return false;
    }
    
    LastCastTurn = CurrentTurn;
    DamageInfo AbilityDamage;
    AbilityDamage.Amount = Damage * (1 + (Caster.GetMagicPwr() / 100) + (Caster.GetEquippedWeapon() ? Caster.GetEquippedWeapon()->GetMagicDamage() / 100 : 0));
    AbilityDamage.Type = Type;
    AbilityDamage.AddAttribute(DamageAttribute);
    AbilityDamage.Instigator = &Caster;
    
    if (AbilityDamage.Amount <0)
    {
        Caster.TakeDamage(AbilityDamage);
        return true;
    }
    
    Target.TakeDamage(AbilityDamage);
    
    return true;
}
