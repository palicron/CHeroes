#pragma once
#include <cstdint>
#include "Types.h"
#include "Weapon.h"

struct DamageInfo;

class Hero
{
public:
	Hero() : Health(1), MaxHealth(1), Strength(1), Intelligence(1), Resource(1), MaxResource(1), Armor(0), MagicArmor(0),AttackPwr(1), MagicPwr(1),EquipWeapon(nullptr)
	{
	}

	Hero(int32_t InHealth, int32_t InStrength, int32_t InIntelligence, int32_t InResource, int32_t InArmor, int32_t InMagicArmor, int32_t InAttackPwr, int32_t InMagicPwr) :
	Health(InHealth), MaxHealth(InHealth), Strength(InStrength), Intelligence(InIntelligence), Resource(InResource), MaxResource(InResource), Armor(InArmor), MagicArmor(InMagicArmor),
	AttackPwr(InAttackPwr), MagicPwr(InMagicPwr),EquipWeapon(nullptr)
	{
	}
	
	Hero(const AttributeSet& Set );

	Hero(const Hero& Other) = delete;
	Hero& operator=(const Hero& Other) = delete;
	Hero(Hero&& Other) noexcept = default;
	Hero& operator=(Hero&& Other) noexcept
	{
		Other.EquipWeapon = this->EquipWeapon;
		EquipWeapon = nullptr;
	};
	virtual ~Hero()
	{
		delete EquipWeapon;
	};

	virtual void MeleeAttack(Hero& Target);

	virtual void UseAbility(const int32_t SlotIndex, Hero& Target);

	virtual void TakeDamage(const DamageInfo& DamageInfo);

	virtual Archetype GetHeroArchetype() const = 0;

	int32_t GetHealth() const
	{
		return Health;
	}
	
	int32_t GetMaxHealth() const
	{
		return MaxHealth;
	}

	int32_t GetStrength() const
	{
		return Strength;
	}

	int32_t GetIntelligence() const
	{
		return Intelligence;
	}
	
	int32_t GetResource() const
	{
		return Resource;
	}
	
	int32_t GetMaxResource() const
	{
		return MaxResource;
	}


	int32_t GetArmor() const
	{
		return Armor;
	}

	int32_t GetMagicArmor() const
	{
		return MagicArmor;
	}

	int32_t GetAttackPwr() const
	{
		return AttackPwr;
	}

	int32_t GetMagicPwr() const
	{
		return MagicPwr;
	}
	
	void EquipAWeapon();

	Weapon* GetEquippedWeapon() const
	{
		return EquipWeapon;
	}

protected:

	int32_t Health;

	int32_t MaxHealth;
	
	int32_t Strength;

	int32_t Intelligence;

	int32_t Resource;

	int32_t MaxResource;
	
	int32_t Armor;

	int32_t MagicArmor;

	int32_t AttackPwr;

	int32_t MagicPwr;
	
	Weapon* EquipWeapon;
	
	EWeaponClass WeaponClass;

	virtual void OnDeath();
};

