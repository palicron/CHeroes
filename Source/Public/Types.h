#pragma once

#include <utility>
#include <string>
class Ability;
class Hero;

enum Archetype : uint8_t
{
	Archetype_Warrior = 0,
	Archetype_Mage = 1,
	Archetype_Barbarian = 2,
	Archetype_Warlock = 3,
	Archetype_Max
};

enum class DamageType
{
	Physical,
	Magic,
	Healing
};

enum EDamageAttribute : uint8_t
{
	None  = 0,
	Slashing = 1 << 0,
	bludgeoning = 1 << 1,
	Fire = 1 << 2,
	Ice = 1 << 3,
	Poison = 1 << 4
};

enum EWeaponClass : uint8_t
{
	EWeaponClass_None = 0,
	EWeaponClass_Sword = 1,
	EWeaponClass_Axe = 2,
	EWeaponClass_Staff = 3,
	EWeaponClass_Wand = 4,
	EWeaponClass_Max
};

struct DamageInfo
{
	int32_t Amount = 0;
	DamageType Type = DamageType::Physical;
	uint8_t DamageAttributes = EDamageAttribute::None;
	Hero* Instigator = nullptr;

	void AddAttribute(const EDamageAttribute Attr)
	{
		DamageAttributes |= Attr;
	}

	bool HasAttribute(const EDamageAttribute Attr) const
	{
		return (DamageAttributes & Attr) != 0;
	}
};

struct HeroArchetypeData
{
	std::pair<int32_t, int32_t> Health;
	std::pair<int32_t, int32_t> Strength ;
	std::pair<int32_t, int32_t> Intelligence;
	std::pair<int32_t, int32_t> Resource;
	std::pair<int32_t, int32_t> Armor;
	std::pair<int32_t, int32_t> MagicArmor;
	std::pair<int32_t, int32_t> AttackPower;
	std::pair<int32_t, int32_t> MagicPower;
};


struct WeaponDamage
{
	std::string WeaponName;
	int32_t MinDamage = 0;
	int32_t MaxDamage = 2;
};
struct AttributeSet
{
	int32_t Health = 0;
	int32_t Str = 0;
	int32_t Int = 0;
	int32_t Resource = 0;
	int32_t armor = 0;
	int32_t MgArmor = 0;
	int32_t AttackPower = 0;
	int32_t MagicPower = 0;
	EWeaponClass weapon_class;
	
};

