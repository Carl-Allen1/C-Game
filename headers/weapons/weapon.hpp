#ifndef WEAPON_H
#define WEAPON_H

#include <vector>
#include "../item.hpp"
#include "../enemy.hpp"

class Weapon: public Item {
protected:
    int strength;
public:
    enum class Type {
        Base,
        SingleTarget,
        AOE
    };

    Weapon();
    Weapon(double durability, double maxDurability, bool breakable, int strength, std::string name);
    virtual ~Weapon() = default;

    virtual void attack(std::vector<Enemy>& targets) = 0;

    std::string toString() const override;
    Item::Type type() override;
    virtual Type weaponType();

    void setStrength(int strength);
    int getStrength() const;
};

#endif // WEAPON_H