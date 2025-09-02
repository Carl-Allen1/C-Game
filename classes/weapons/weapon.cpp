#include "../headers/weapons/weapon.hpp"
#include <iostream>

Weapon::Weapon() {}

Weapon::Weapon(double durability, double maxDurability, bool breakable, int strength, std::string name) {
    this->durability = durability;
    this->maxDurability = maxDurability;
    this->breakable = breakable;
    this->broken = false;
    this->strength = strength;
    this->name = name;
}

std::string Weapon::toString() const { return name + " (Damage: " + std::to_string(strength) + ", Durability: " + std::to_string(static_cast<int>(durability)) + ")"; }

Item::Type Weapon::type() { return Item::Type::Weapon; }
Weapon::Type Weapon::weaponType() { return Weapon::Type::Base; }

void Weapon::setStrength(int strength) { this->strength = strength; }

int Weapon::getStrength() const { return strength; }