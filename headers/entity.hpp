#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
    double health;
    double armor;
    bool isDead;
public:
    virtual ~Entity() = default;

    Entity();
    Entity(double setHealth, double setArmor);
    void takeDamage(double amt);
    void healDamage(double amt);
    void setArmor(double setArmor);
    double getHealth();
    double getArmor();
    bool getDead();
};

#endif // ENTITY_H