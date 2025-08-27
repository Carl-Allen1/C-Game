#include "../headers/item.hpp"

Item::Item() {}

Item::Item(double setDurability, double setMaxDurability, bool setBreakable, std::string setName) {
    durability = setDurability;
    maxDurability = setMaxDurability;
    breakable = setBreakable;
    broken = false;
    name = setName;
}

std::string Item::toString() const { return name + " (Durability: " + std::to_string(durability) + ")"; }

Item::Type Item::type() { return Item::Type::Base; }

void Item::damage(double amt) {
    if(breakable) { durability -= amt; }
    if(durability <= 0) { broken = true; }
}

void Item::repair(double amt) {
    if(durability + amt <= maxDurability) { durability += amt; }
}

// Setters
void Item::setDurability(double setDurability) { durability = setDurability; }
void Item::setMaxDurability(double setMaxDurability) { maxDurability = setMaxDurability; }
void Item::setBreakable(bool setBreakable) { breakable = setBreakable; }
void Item::setBroken(bool setBroken) { broken = setBroken; }
void Item::setName(std::string setName) { name = setName; }

// Getters
double Item::getDurability() { return durability; }
double Item::getMaxDurability() { return maxDurability; }
bool Item::getBreakable() { return breakable; }
bool Item::getBroken() { return broken; }
std::string Item::getName() { return name; }