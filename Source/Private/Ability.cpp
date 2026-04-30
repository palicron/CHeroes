#include "Ability.h"
#include "Hero.h"

bool Ability::CastAbility(Hero& Target, Hero& Caster, const int32_t CurrentTurn)
{
    if (CurrentTurn - LastCastTurn >= Cooldown && Caster.GetResource() < Cost)
    {
        return false;
    }

    DamageInfo AbilityDamage;
    AbilityDamage.Amount = Damage * (1 + (Caster.GetMagicPwr() / 100) + (Caster.GetEquippedWeapon() ? Caster.GetEquippedWeapon()->GetMagicDamage() / 100 : 0));
    AbilityDamage.Type = Type;
    AbilityDamage.AddAttribute(DamageAttribute);
    AbilityDamage.Instigator = &Caster;
    Target.TakeDamage(AbilityDamage);
    
    return true;
}
