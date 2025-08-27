#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
    double health;
    bool isDead;
public:
    virtual ~Entity() = default;

    Entity();
    Entity(double setHealth);
    void takeDamage(double amt, double armor);
    void healDamage(double amt);
    double getHealth();
    bool getDead();
};

#endif // ENTITY_H