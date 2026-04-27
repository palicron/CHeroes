#pragma once


class Hero;

enum class Archetype
{
	Warrior,
	Mage,
	Barbarian,
	Warlock
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

