#ifndef PLAYER_H
#define PLAYER_H

#include "entity.hpp"
#include "inventory.hpp"

class Player: public Entity {
private:
    Inventory inventory;
    int const defaultSize = 10;
public:
    Player();
    Player(int inventorySize, double setHealth, double setArmor);
    Inventory& getInventory();
};

#endif // PLAYER_H