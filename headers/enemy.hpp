#ifndef ENEMY_H
#define ENEMY_H

#include "entity.hpp"

class Enemy: public Entity {
private:
    double damage;
public:
    Enemy();
    Enemy(double setDamage, double setHealth);
    void setDamage(double setDamage);
    double getDamage();
};

#endif // ENEMY_H