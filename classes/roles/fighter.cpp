#include "../headers/roles/fighter.hpp"

Fighter::Fighter() {}

Fighter::Fighter(double armor, int attacks) : Role(attacks) {
    this->armor = armor;
    this->primary = std::make_unique<Slash>(3, false, true, 10);
    this->secondary = std::make_unique<Reinforce>(4, 2, true, false, 2);
    this->ultimate = std::make_unique<Frenzy>(5, 3, true, false, 2);
}

void Fighter::usePrimary(GameContext gctx) {
    primary->execute(gctx);
}

void Fighter::useSecondary(GameContext gctx) {
    secondary->execute(gctx);
}

void Fighter::useUltimate(GameContext gctx) {
    ultimate->execute(gctx);
}

Role::Type Fighter::type() { return Role::Type::Fighter; }
bool Fighter::hasArmor() { return true; }

void Fighter::setArmor(double armor) { this->armor = armor; }

double Fighter::getArmor() const { return armor; }