#include "../headers/roles/fighter.hpp"

Fighter::Fighter() {}

Fighter::Fighter(double setArmor, int setSecDuration) {
    armor = setArmor;
    secDuration = setSecDuration;
    ultUsed = false;
}

void Fighter::usePrimary() {} // For override
double Fighter::usePrimary(double damage) {
    return damage * 1.5;
}

void Fighter::useSecondary() {
    armor *= 2;
}

void Fighter::useUltimate() {
    attacks = 3;
    ultUsed = true;
}

Role::Type Fighter::type() { return Role::Type::Fighter; }
bool Fighter::hasArmor() { return true; }

void Fighter::setArmor(double setArmor) { armor = setArmor; }
void Fighter::setSecDuration(int setSecDuration) { secDuration = setSecDuration; }
void Fighter::setUltUsed(bool setUltUsed) { ultUsed = setUltUsed; }

double Fighter::getArmor() { return armor; }
int Fighter::getSecDuration() { return secDuration; }
bool Fighter::getUltUsed() { return ultUsed; }