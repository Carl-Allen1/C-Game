#ifndef PLAYER_H
#define PLAYER_H

#include "entity.hpp"
#include "inventory.hpp"
#include "roles/role.hpp"
#include "weapons/weapon.hpp"

class Player: public Entity {
private:
    std::unique_ptr<Role> role;
    std::unique_ptr<Weapon> weapon;
    Inventory inventory;
    int const defaultSize = 10;
public:
    Player();
    Player(int inventorySize, double setHealth);

    void setRole(std::unique_ptr<Role> setRole);
    void setWeapon(std::unique_ptr<Weapon> setWeapon);

    Inventory& getInventory();

    bool roleHasArmor();
    double getRoleArmor();
};

#endif // PLAYER_H