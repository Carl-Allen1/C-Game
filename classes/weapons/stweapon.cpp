#include "../headers/weapons/stweapon.hpp"
#include <iostream>

STWeapon::STWeapon() {}

STWeapon::STWeapon(int setStrength) {
    strength = setStrength;
}

void STWeapon::attack(std::vector<Enemy> targets) {
    targets.front().takeDamage(strength, 0);

    if(targets.front().getHealth() <= 0) std::cout << "The enemy died!" << std::endl;
}