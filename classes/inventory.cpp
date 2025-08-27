#include "../headers/inventory.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

Inventory::Inventory() {}

Inventory::Inventory(int setMaxItems) {
    maxItems = setMaxItems;
}

void Inventory::toString() const {
    int counter = 1;
    
    for(const auto& i : items) {
        std::cout << counter << ". " << i->toString() << '\n';
        counter++;
    }
}

void Inventory::addItem(std::shared_ptr<Item> item) {
    if(items.size() == maxItems) { return; }
    items.push_back(item);
}

void Inventory::removeItem(Item item) {
    auto index = std::find_if(items.begin(), items.end(),
        [&](const std::shared_ptr<Item>& ptr) {
            return *ptr == item;
        });
    if(index != items.end()) { items.erase(index); }
}

void Inventory::setMaxItems(int setMaxItems) { maxItems = setMaxItems; }

std::vector<std::shared_ptr<Item>> Inventory::getItems() { return items; }
int Inventory::getMaxItems() { return maxItems; }