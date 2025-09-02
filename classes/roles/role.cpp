#include "../headers/roles/role.hpp"

Role::Role() {}

Role::Role(int attacks) {
    this->attacks = attacks;
}

void Role::checkCooldowns() {
    if(primary->getUsed()) { primary->incCTracker(); }
    if(primary->getCTracker() == primary->getCooldown()) { primary->setCTracker(0); primary->setUsed(false); }

    if(secondary->getUsed()) { secondary->incCTracker(); }
    if(secondary->getCTracker() == secondary->getCooldown()) { secondary->setCTracker(0); secondary->setUsed(false); }

    if(ultimate->getUsed()) { ultimate->incCTracker(); }
    if(ultimate->getCTracker() == ultimate->getCooldown()) { ultimate->setCTracker(0); ultimate->setUsed(false); }
}

void Role::checkDurations(GameContext gctx) {
    if(primary->getDurable()) {
        if(primary->getDTracker() == primary->getDuration()) {
            primary->revert(gctx);
            primary->setDTracker(0);
        } else { primary->incDTracker(); }
    }

    if(secondary->getDurable()) {
        if(secondary->getDTracker() == secondary->getDuration()) {
            secondary->revert(gctx);
            secondary->setDTracker(0);
        } else { secondary->incDTracker(); }
    }

    if(ultimate->getDurable()) {
        if(ultimate->getDTracker() == ultimate->getDuration()) {
            ultimate->revert(gctx);
            ultimate->setDTracker(0);
        } else { ultimate->incDTracker(); }
    }
}

void Role::setAttacks(int setAttacks) { attacks = setAttacks; }

int Role::getAttacks() { return attacks; }
std::unique_ptr<Ability> Role::getPrimary() { return std::move(primary); }
std::unique_ptr<Ability> Role::getSecondary() { return std::move(secondary); }
std::unique_ptr<Ability> Role::getUltimate() { return std::move(ultimate); }