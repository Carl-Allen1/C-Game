#include "../headers/inventory.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

Inventory::Inventory() {}

Inventory::Inventory(int setMaxItems, int setMaxWeapons) {
    maxItems = setMaxItems;
    maxWeapons = setMaxWeapons;
}

void Inventory::toString() const {
    int counter = 1;
    
    for(const auto& i : items) {
        std::cout << counter << ". " << i->toString() << '\n';
        counter++;
    }
}

void Inventory::addItem(std::unique_ptr<Item> item) {
    if(items.size() == static_cast<long>(maxItems)) { std::cout << "Inventory is full!" << std::endl; return; }
    items.push_back(std::move(item));
}

void Inventory::addWeapon(std::unique_ptr<Weapon> weapon) {
    if(weapons.size() == maxWeapons) { std::cout << "Weapon slots are full!" << std::endl; return; }
    weapons.push_back(std::move(weapon));
}

void Inventory::removeItem(Item item) {
    auto index = std::find_if(items.begin(), items.end(),
        [&](const std::unique_ptr<Item>& ptr) {
            return *ptr == item;
        });
    if(index != items.end()) { items.erase(index); }
}

void Inventory::removeWeapon(const Weapon& weapon) {
    auto index = std::find_if(weapons.begin(), weapons.end(),
        [&](const std::unique_ptr<Weapon>& ptr) {
            return ptr.get() == &weapon;
        });
    if(index != weapons.end()) { weapons.erase(index); }
}

void Inventory::setMaxItems(int setMaxItems) { maxItems = setMaxItems; }
void Inventory::setMaxWeapons(int setMaxWeapons) { maxWeapons = setMaxWeapons; }

std::vector<std::unique_ptr<Item>>& Inventory::getItems() { return items; }
std::vector<std::unique_ptr<Weapon>>& Inventory::getWeapons() { return weapons; }
int Inventory::getMaxItems() { return maxItems; }
int Inventory::getMaxWeapons() { return maxWeapons; }