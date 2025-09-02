#ifndef FIGHTER_H
#define FIGHTER_H

#include "role.hpp"
#include "../abilities/slash.hpp"
#include "../abilities/reinforce.hpp"
#include "../abilities/frenzy.hpp"
#include <memory>

class Fighter: public Role {
private:
    double armor;
public:
    Fighter();
    Fighter(double armor, int attacks);

    void usePrimary(GameContext gctx) override;
    void useSecondary(GameContext gctx) override;
    void useUltimate(GameContext gctx) override;
    Role::Type type() override;
    bool hasArmor() override;

    void setArmor(double armor) override;

    double getArmor() const override;
};

#endif // FIGHTER_H