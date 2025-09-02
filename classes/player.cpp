#include "../headers/player.hpp"
#include "../headers/weapons/stweapon.hpp"
#include "../headers/weapons/aoeweapon.hpp"
#include "../headers/color.hpp"
#include <iostream>

Player::Player() : inventory(7, 3) {}

Player::Player(int inventorySize, double health) : inventory(inventorySize, 3) {
    this->health = health;
}

void Player::setRole(std::unique_ptr<Role> role) {
    this->role = std::move(role);

    std::cout << Color::colorCodes[Color::Colors::Yellow] << "Primary Ability: " << this->role->getPrimary()->getDescription()
        << std::endl;
    std::cout << "Secondary Ability: " << this->role->getSecondary()->getDescription() << std::endl;
    std::cout << "Ultimate Ability: " << this->role->getUltimate()->getDescription()
        << Color::colorCodes[Color::Colors::Reset] << std::endl;
}

void Player::setWeapon(std::unique_ptr<Weapon> setWeapon) {
    weapon = std::move(setWeapon);
    inventory.addWeapon(std::move(weapon));
}

Inventory& Player::getInventory() { return inventory; }
std::unique_ptr<Role> Player::getRole() { return std::move(role); }
std::unique_ptr<Weapon> Player::getWeapon() { return std::move(weapon); }

bool Player::roleHasArmor() { return role->hasArmor(); }
double Player::getRoleArmor() { return role->getArmor(); }