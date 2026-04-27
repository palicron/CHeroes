#pragma once
#include "Caster.h"

class Mage: public Caster
{
public:
    
    Mage() : Caster() {}
    Mage(const AttributeSet& Set) : Caster(Set) {}
    
    virtual Archetype GetHeroArchetype() const override
    {
        return CurrentType;
    }
private:
    
    const Archetype CurrentType = Archetype::Archetype_Mage;
    
};
