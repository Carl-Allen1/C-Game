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

    template<typename T, typename... Args>
    void setRole(Args&&... args) {
        static_assert(std::is_base_of<Role, T>::value, "T must be a subclass of Role");
        role = std::make_unique<T>(std::forward<Args>(args)...);
        
        printAbilities();
    }

    void printAbilities();
    void setWeapon(std::unique_ptr<Weapon> setWeapon);

    Inventory& getInventory();
    std::unique_ptr<Role>& getRole();
    std::unique_ptr<Weapon>& getWeapon();

    bool roleHasArmor();
    double getRoleArmor();
};

#endif // PLAYER_H