#include "../headers/weapons/aoeweapon.hpp"

AOEWeapon::AOEWeapon() {}

AOEWeapon::AOEWeapon(int setTargetCount) {
    targetCount = setTargetCount;
}

void AOEWeapon::attack(std::vector<Enemy> targets) {
    for(int i = targets.size() - 1, j = 0; j < targetCount; i--, j++) {
        if(i < 0) i = 0;

        targets[i].takeDamage(strength, 0);
    }
}

void AOEWeapon::setTargetCount(int setTargetCount) { targetCount = setTargetCount; }

int AOEWeapon::getTargetCount() { return targetCount; }