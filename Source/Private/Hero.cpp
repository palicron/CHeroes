#include "Hero.h"
#include "Types.h"
#include <algorithm>
#include <iostream>

#include "GameManager.h"
#include "HeroFactory.h"

Hero::Hero(const AttributeSet& Set)
{
	Health = Set.Health;
	MaxHealth = Set.Health;
	MaxResource = Set.Resource;
	Strength = Set.Str;
	Intelligence = Set.Int;
	Resource = Set.Resource;
	Armor = Set.armor;
	MagicArmor = Set.MgArmor;
	AttackPwr = Set.AttackPower;
	MagicPwr = Set.MagicPower;
	WeaponClass = Set.weapon_class;
}

void Hero::MeleeAttack(Hero& Target)
{
	DamageInfo NewDamage;
	
	const int32_t WeaponDamage = EquipWeapon ? EquipWeapon->GetAttackDamage() : 1;
	NewDamage.Amount = WeaponDamage * (1 + ((Strength / 100) + AttackPwr / 200));
	NewDamage.Instigator = &Target;
	if (EquipWeapon)
	{
		for (const EDamageAttribute& Attribute : EquipWeapon->GetDamageAttributes())
		{
			NewDamage.AddAttribute(Attribute);
		}
	}
	

	Target.TakeDamage(NewDamage);
}

void Hero::UseAbility(const int32_t SlotIndex, Hero& Target)
{
	int32_t indx = SlotIndex;
	if (indx < 0 || indx >= Abilities.size())
	{
		return;
	}
	
	if (Abilities[SlotIndex])
	{
		if (Abilities[SlotIndex]->CastAbility(Target,*this,GameManager::GetCurrentTurn()))
		{
			Resource -= Abilities[SlotIndex]->GetCost();
		}
	}
	
}

void Hero::TakeDamage(const DamageInfo& DamageInfo)
{
	
	int32_t DamageToTake = DamageInfo.Amount;


	if (DamageInfo.Type == DamageType::Physical)
	{
		DamageToTake = std::max(DamageToTake - (1 - (Armor / 100)), 1);
		
		std::cout << "====================================\n";
		std::cout << HeroFactory::HeroClassToString(GetHeroArchetype()) << " Takes Physical Damage = " << DamageToTake <<" \n";
		std::cout << "====================================\n";
	}
	else if (DamageInfo.Type == DamageType::Magic)
	{
		std::cout << "====================================\n";
		std::cout << HeroFactory::HeroClassToString(GetHeroArchetype()) << " Takes Magic Damage = " << DamageToTake <<" \n";
		std::cout << "====================================\n";
		DamageToTake = std::max(DamageToTake - (1 - (MagicArmor / 100)), 1);
	}
	else
	{
		//This will be a heal
		DamageToTake *= -1;
		std::cout << "====================================\n";
		std::cout << HeroFactory::HeroClassToString(GetHeroArchetype()) << " Heals for  = " << DamageToTake <<" \n";
		std::cout << "====================================\n";
	}

	
	Health = std::clamp(Health - DamageToTake, 0, MaxHealth);

	if (Health <= 0)
	{
		OnDeath();
	}

}

void Hero::SetAbility(std::array<std::shared_ptr<Ability>, 4>& InAbilities)
{
	Abilities = std::move(InAbilities);
}

void Hero::EquipAWeapon()
{
	WeaponDamage Damage = HeroFactory::GetDamageByType(WeaponClass);
	EquipWeapon = new Weapon(std::move(Damage.WeaponName),Damage.MinDamage,Damage.MaxDamage,0,WeaponClass,std::vector<EDamageAttribute>());
	
}

Ability* Hero::GetAbility(const int32_t SlotIndex) const
{
	if (SlotIndex < 0 || SlotIndex > 3)
	{
		return nullptr;
	}
	
	return Abilities[SlotIndex].get();
}

void Hero::OnDeath()
{
}
