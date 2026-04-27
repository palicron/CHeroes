#pragma once
#include "Caster.h"

class Warlock: public Caster
{
public:
    Warlock() : Caster() {}
    Warlock(const AttributeSet& Set) : Caster(Set) {}
    
    virtual Archetype GetHeroArchetype() const override
    {
        return CurrentType;
    }
    
private:

    Archetype CurrentType = Archetype::Archetype_Warlock;
};
