#include "../headers/weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(double setDurability, double setMaxDurability, bool setBreakable, int setStrength, std::string setName) {
    durability = setDurability;
    maxDurability = setMaxDurability;
    breakable = setBreakable;
    broken = false;
    strength = setStrength;
    name = setName;
}

std::string Weapon::toString() const { return name + " (Damage: " + std::to_string(strength) + ", Durability: " + std::to_string(static_cast<int>(durability)) + ")"; }

Item::Type Weapon::type() { return Item::Type::Weapon; }

void Weapon::setStrength(int setStrength) { strength = setStrength; }

int Weapon::getStrength() { return strength; }