#ifndef AOE_WEAPON_H
#define AOE_WEAPON_H

#include <memory>
#include "weapon.hpp"

class AOEWeapon: public Weapon {
private:
    int targetCount;
public:
    AOEWeapon();
    AOEWeapon(int targetCount, int strength, std::string name);

    Weapon::Type weaponType() override;

    void attack(std::vector<Enemy>& targets) override;

    void setTargetCount(int targetCount);

    int getTargetCount();
};

#endif // AOE_WEAPON_H