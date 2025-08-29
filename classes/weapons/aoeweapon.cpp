#include "../headers/weapons/aoeweapon.hpp"
#include "../headers/color.hpp"
#include <iostream>
#include <thread>
#include <chrono>

AOEWeapon::AOEWeapon() {}

AOEWeapon::AOEWeapon(int setTargetCount, int setStrength, std::string setName) {
    targetCount = setTargetCount;
    strength = setStrength;
    name = setName;
}

Weapon::Type AOEWeapon::weaponType() { return Weapon::Type::AOE; }

void AOEWeapon::attack(std::vector<Enemy>& targets) {
    int actualTargets = std::min(targetCount, static_cast<int>(targets.size()));
    
    for(int i = 0; i < actualTargets; i++) {
        targets[i].takeDamage(strength, 0);

        std::cout << Color::colorCodes[Color::Colors::Blue] << "Enemy " << i + 1 << " took " << strength << " damage!"
            << Color::colorCodes[Color::Colors::Reset] << std::endl;

        if(targets[i].getHealth() <= 0) {
            std::cout << Color::colorCodes[Color::Colors::BrightBlue] << "The enemy died!"
                << Color::colorCodes[Color::Colors::Reset] << std::endl;
            targets[i].setDead(true);

            if(targets.size() == 1) return;
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void AOEWeapon::setTargetCount(int setTargetCount) { targetCount = setTargetCount; }

int AOEWeapon::getTargetCount() { return targetCount; }