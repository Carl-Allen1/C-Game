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
    Inventory(int maxItems, int maxWeapons);
    void toString() const;
    
    void addItem(std::unique_ptr<Item> item);
    void addWeapon(std::unique_ptr<Weapon> weapon);
    void removeItem(Item item);
    void removeWeapon(const Weapon& weapon);

    void setMaxItems(int maxItems);
    void setMaxWeapons(int maxWeapons);

    const std::vector<std::unique_ptr<Item>>& getItems() const;
    const std::vector<std::unique_ptr<Weapon>>& getWeapons() const;
    int getMaxItems() const;
    int getMaxWeapons() const;
};

#endif // INVENTORY_H