#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
    double health;
    bool isDead;
public:
    virtual ~Entity() = default;

    Entity();
    Entity(double health);

    void takeDamage(double amt, double armor);
    void healDamage(double amt);

    void setDead(bool isDead);
    
    double getHealth();
    bool getDead() const;
};

#endif // ENTITY_H