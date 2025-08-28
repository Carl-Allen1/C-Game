#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include "item.hpp"
#include "./weapons/weapon.hpp"

class Inventory {
private:
    std::vector<std::unique_ptr<Item>> items;
    std::vector<std::unique_ptr<Weapon>> weapons;
    int maxItems;
    int maxWeapons;
public:
    Inventory();
    Inventory(int setMaxItems, int setMaxWeapons);
    void toString() const;
    void addItem(std::unique_ptr<Item> item);
    void addWeapon(std::unique_ptr<Weapon> weapon);
    void removeItem(Item item);
    void removeWeapon(const Weapon& weapon);
    void setMaxItems(int setMaxItems);
    void setMaxWeapons(int setMaxWeapons);
    std::vector<std::unique_ptr<Item>>& getItems();
    std::vector<std::unique_ptr<Weapon>>& getWeapons();
    int getMaxItems();
    int getMaxWeapons();
};

#endif // INVENTORY_H