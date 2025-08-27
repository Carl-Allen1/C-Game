#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include "item.hpp"

class Inventory {
private:
    std::vector<std::shared_ptr<Item>> items;
    int maxItems;
public:
    Inventory();
    Inventory(int maxItems);
    void toString() const;
    void addItem(std::shared_ptr<Item> item);
    void removeItem(Item item);
    void setMaxItems(int setMaxItems);
    std::vector<std::shared_ptr<Item>> getItems();
    int getMaxItems();
};

#endif // INVENTORY_H