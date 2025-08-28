#ifndef AOE_WEAPON_H
#define AOE_WEAPON_H

#include "weapon.hpp"

class AOEWeapon: public Weapon {
private:
    int targetCount;
public:
    AOEWeapon();
    AOEWeapon(int setTargetCount, int setStrength, std::string setName);

    Weapon::Type weaponType() override;

    void attack(std::vector<Enemy> targets) override;

    void setTargetCount(int setTargetCount);

    int getTargetCount();
};

#endif // AOE_WEAPON_H