#include "../headers/player.hpp"

Player::Player() : inventory(defaultSize) {}

Player::Player(int inventorySize, double setHealth) : inventory(inventorySize) {
    health = setHealth;
}

void Player::setRole(std::unique_ptr<Role> setRole) {
    role = std::move(setRole);
}

void Player::setWeapon(std::unique_ptr<Weapon> setWeapon) {
    weapon = std::move(setWeapon);
    inventory.addItem(std::make_shared<Weapon>(weapon));
}

Inventory& Player::getInventory() { return inventory; }

bool Player::roleHasArmor() { return role->hasArmor(); }
double Player::getRoleArmor() { return role->getArmor(); }