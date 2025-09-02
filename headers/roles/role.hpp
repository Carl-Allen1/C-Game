#ifndef ROLE_H
#define ROLE_H

#include "../abilities/ability.hpp"
#include <memory>

class Role {
protected:
    int attacks;

    std::unique_ptr<Ability> primary;
    std::unique_ptr<Ability> secondary;
    std::unique_ptr<Ability> ultimate;
public:
    enum class Type {
        Any,
        Fighter
    };

    Role();
    Role(int attacks);
    virtual ~Role() = default;

    virtual void checkCooldowns();
    virtual void checkDurations(GameContext gctx);

    virtual void usePrimary(GameContext gctx) = 0;
    virtual void useSecondary(GameContext gctx) = 0;
    virtual void useUltimate(GameContext gctx) = 0;
    virtual Type type() = 0;
    virtual bool hasArmor() = 0;

    void setAttacks(int setAttacks);
    virtual void setArmor(double armor) = 0;

    int getAttacks();
    virtual double getArmor() = 0;

    virtual std::unique_ptr<Ability> getPrimary();
    virtual std::unique_ptr<Ability> getSecondary();
    virtual std::unique_ptr<Ability> getUltimate();
};

#endif // ROLE_H