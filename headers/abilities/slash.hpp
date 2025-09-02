#ifndef SLASH_H
#define SLASH_H

#include "ability.hpp"

class Slash: public Ability {
private:
    int damage;
public:
    Slash();
    Slash(int cooldown, bool durable, bool unlocked, int damage);

    void execute(GameContext gctx) override;
};

#endif // SLASH_H