#include "../headers/weapons/stweapon.hpp"
#include <iostream>
#include <thread>
#include <chrono>

STWeapon::STWeapon() {}

STWeapon::STWeapon(int setStrength, std::string setName) {
    strength = setStrength;
    name = setName;
}

Weapon::Type STWeapon::weaponType() { return Weapon::Type::SingleTarget; }

void STWeapon::attack(std::vector<Enemy> targets) {
    targets.front().takeDamage(strength, 0);

    std::cout << "The enemy was hit for " << strength << " damage!" << std::endl;

    if(targets.front().getHealth() <= 0) std::cout << "The enemy died!" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
}