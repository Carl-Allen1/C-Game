#include "../headers/player.hpp"

Player::Player() : inventory(defaultSize) {}

Player::Player(int inventorySize, double setHealth, double setArmor) : inventory(inventorySize) {
    health = setHealth;
    armor = setArmor;
}

Inventory& Player::getInventory() { return inventory; }