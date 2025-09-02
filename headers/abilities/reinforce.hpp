#ifndef REINFORCE_H
#define REINFORCE_H

#include "ability.hpp"

class Reinforce: public Ability {
private:
    double increase;
public:
    Reinforce();
    Reinforce(int cooldown, int duration, bool durable, bool unlocked, double increase);

    void execute(GameContext gctx) override;
    void revert(GameContext gctx) override;
};

#endif // REINFORCE_H