#ifndef NULL_ABILITY_H
#define NULL_ABILITY_H

#include "ability.hpp"

class NullAbility: public Ability {
public:
    std::string getDescription() const override;
};

#endif