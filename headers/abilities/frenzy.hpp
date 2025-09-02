#ifndef FRENZY_H
#define FRENZY_H

#include "ability.hpp"

class Frenzy: public Ability {
private:
    int increase;
public:
    Frenzy();
    Frenzy(int cooldown, int duration, bool durable, bool unlocked, int increase);

    void execute(GameContext gctx) override;
    void revert(GameContext gctx) override;
};

#endif // FRENZY_H