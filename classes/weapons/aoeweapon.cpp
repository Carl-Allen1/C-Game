#include "../headers/weapons/aoeweapon.hpp"
#include <iostream>

AOEWeapon::AOEWeapon() {}

AOEWeapon::AOEWeapon(int setTargetCount, int setStrength, std::string setName) {
    targetCount = setTargetCount;
    strength = setStrength;
    name = setName;
}

Weapon::Type AOEWeapon::weaponType() { return Weapon::Type::AOE; }

void AOEWeapon::attack(std::vector<Enemy> targets) {
    for(int i = targets.size() - 1, j = 0; j < targetCount; i--, j++) {
        if(i < 0) i = 0;

        targets[i].takeDamage(strength, 0);

        std::cout << "The enemy took " << strength << " damage!" << std::endl;

        if(targets[i].getHealth() <= 0) std::cout << "The enemy died!" << std::endl;
    }
}

void AOEWeapon::setTargetCount(int setTargetCount) { targetCount = setTargetCount; }

int AOEWeapon::getTargetCount() { return targetCount; }