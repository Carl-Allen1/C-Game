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
public:
    Player();
    Player(int inventorySize, double health);

    void setRole(std::unique_ptr<Role> role);
    void setWeapon(std::unique_ptr<Weapon> setWeapon);

    Inventory& getInventory();
    std::unique_ptr<Role> getRole();
    std::unique_ptr<Weapon> getWeapon();

    bool roleHasArmor();
    double getRoleArmor();
};

#endif // PLAYER_H