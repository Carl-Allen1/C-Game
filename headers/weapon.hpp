#ifndef WEAPON_H
#define WEAPON_H

#include "item.hpp"

class Weapon: public Item {
private:
    int strength;
public:
    Weapon();
    Weapon(double setDurability, double setMaxDurability, bool setBreakable, int setStrength, std::string setName);
    std::string toString() const override;
    Item::Type type() override;
    void setStrength(int setStrength);
    int getStrength();
};

#endif // WEAPON_H