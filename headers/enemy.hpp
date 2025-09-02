#ifndef ENEMY_H
#define ENEMY_H

#include "entity.hpp"

class Enemy: public Entity {
private:
    double damage;
public:
    Enemy();
    Enemy(double damage, double health);
    
    void setDamage(double damage);
    double getDamage();
};

#endif // ENEMY_H