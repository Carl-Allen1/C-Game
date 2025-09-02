#include "../headers/item.hpp"

Item::Item() {}

Item::Item(double durability, double maxDurability, bool breakable, std::string name) {
    this->durability = durability;
    this->maxDurability = maxDurability;
    this->breakable = breakable;
    this->broken = false;
    this->name = name;
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
void Item::setDurability(double durability) { this->durability = durability; }
void Item::setMaxDurability(double maxDurability) { this->maxDurability = maxDurability; }
void Item::setBreakable(bool breakable) { this->breakable = breakable; }
void Item::setBroken(bool broken) { this->broken = broken; }
void Item::setName(std::string name) { this->name = name; }

// Getters
double Item::getDurability() { return durability; }
double Item::getMaxDurability() { return maxDurability; }
bool Item::getBreakable() { return breakable; }
bool Item::getBroken() { return broken; }
std::string Item::getName() { return name; }