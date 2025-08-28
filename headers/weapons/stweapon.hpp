#ifndef ST_WEAPON_H
#define ST_WEAPON_H

#include "weapon.hpp"

class STWeapon: public Weapon {
public:
    STWeapon();
    STWeapon(int setStrength, std::string setName);

    Weapon::Type weaponType() override;

    void attack(std::vector<Enemy> targets) override;
};

#endif // ST_WEAPON_H (Single-Target Weapon)