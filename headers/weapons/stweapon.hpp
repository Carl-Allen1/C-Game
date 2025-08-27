#ifndef ST_WEAPON_H
#define ST_WEAPON_H

#include "weapon.hpp"

class STWeapon: public Weapon {
public:
    STWeapon();
    void attack(std::vector<Enemy> targets) override;
};

#endif // ST_WEAPON_H (Single-Target Weapon)