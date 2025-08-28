#include "../headers/player.hpp"
#include "../headers/weapons/stweapon.hpp"
#include "../headers/weapons/aoeweapon.hpp"

Player::Player() : inventory(7, 3) {}

Player::Player(int inventorySize, double setHealth) : inventory(inventorySize, 3) {
    health = setHealth;
}

void Player::setRole(std::unique_ptr<Role> setRole) {
    role = std::move(setRole);
}

void Player::setWeapon(std::unique_ptr<Weapon> setWeapon) {
    weapon = std::move(setWeapon);
    inventory.addWeapon(std::move(weapon));
}

Inventory& Player::getInventory() { return inventory; }

bool Player::roleHasArmor() { return role->hasArmor(); }
double Player::getRoleArmor() { return role->getArmor(); }