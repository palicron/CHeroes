#include "Hero.h"
#include "Types.h"
#include <algorithm>

void Hero::MeleeAttack(Hero& Target) const
{
	DamageInfo NewDamage;
	//TODO NEED TO ADD A Grap Weapon
	NewDamage.Amount = ((10 * Strength) / 100) + ((10 * AttackPwr) / 200) + 10;
	NewDamage.Instigator = &Target;
	NewDamage.AddAttribute(bludgeoning);

	Target.TakeDamage(NewDamage);
}

void Hero::UseAbility(const int32_t SlotIndex, Hero& Target)
{
	//TODO TEMPORAL LOGIC TO COMPILE 
	int32_t indx = SlotIndex;
	if (indx> 0)
	{
		Target.MeleeAttack(*this);
	}
	
}

void Hero::TakeDamage(const DamageInfo& DamageInfo)
{
	//TODO for the moment 1 or armor is 1% reduction of damage
	int32_t DamageToTake = DamageInfo.Amount;

	if (DamageInfo.Type == DamageType::Physical)
	{
		//TODO Need to manage attribute reductions
		DamageToTake = std::max(DamageToTake - (1 - (Armor / 100)), 1);
	}
	else if (DamageInfo.Type == DamageType::Magic)
	{
		DamageToTake = std::max(DamageToTake - (1 - (MagicArmor / 100)), 1);
	}
	else
	{
		//This will be a heal
		DamageToTake *= -1;
	}

	Health -= DamageToTake;

	if (Health <= 0)
	{
		OnDeath();
	}

}

void Hero::OnDeath()
{
}
