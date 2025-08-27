#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    double durability;
    double maxDurability;
    bool breakable;
    bool broken;
    std::string name;
public:
    bool operator==(const Item& other) const {
        bool equal = true;
        equal &= (name == other.name);
        equal &= (durability == other.durability);
        equal &= (breakable == other.breakable);
        
        return equal;
    }
    virtual ~Item() = default;

    enum class Type {
        Base,
        Weapon
    };
    Item();
    Item(double setDurability, double setMaxDurability, bool setBreakable, std::string setName);
    virtual std::string toString() const;
    virtual Type type();
    void damage(double amt);
    void repair(double amt);
    void setDurability(double setDurability);
    void setMaxDurability(double setMaxDurability);
    void setBreakable(bool setBreakable);
    void setBroken(bool setBroken);
    void setName(std::string setName);
    double getDurability();
    double getMaxDurability();
    bool getBreakable();
    bool getBroken();
    std::string getName();
};

#endif // ITEM_H