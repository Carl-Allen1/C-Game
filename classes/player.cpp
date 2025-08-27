#include "../headers/player.hpp"

Player::Player() : inventory(defaultSize) {}

Player::Player(int inventorySize, double setHealth) : inventory(inventorySize) {
    health = setHealth;
}

Inventory& Player::getInventory() { return inventory; }