#include "../headers/weapons/stweapon.hpp"
#include "../headers/color.hpp"
#include <iostream>
#include <thread>
#include <chrono>

STWeapon::STWeapon() {}

STWeapon::STWeapon(int setStrength, std::string setName) {
    strength = setStrength;
    name = setName;
}

Weapon::Type STWeapon::weaponType() { return Weapon::Type::SingleTarget; }

void STWeapon::attack(std::vector<Enemy>& targets) {
    targets.front().takeDamage(strength, 0);

    std::cout << Color::colorCodes[Color::Colors::Blue] << "The enemy was hit for " << strength << " damage!"
        << Color::colorCodes[Color::Colors::Reset] << std::endl;

    if(targets.front().getHealth() <= 0) {
        std::cout << Color::colorCodes[Color::Colors::BrightBlue] << "The enemy died!"
            << Color::colorCodes[Color::Colors::Reset] << std::endl;
        targets.front().setDead(true);
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));
}