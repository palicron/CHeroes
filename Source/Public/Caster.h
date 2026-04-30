#pragma once
#include "Hero.h"

class Caster: public Hero
{
public:
    Caster() : Hero() {}
    Caster(const AttributeSet& Set) : Hero(Set) {}
    
    virtual void EndTurn() override;
};
