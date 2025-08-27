#include "../headers/entity.hpp"
#include <cmath>

Entity::Entity() {}

Entity::Entity(double setHealth) {
    health = setHealth;
    isDead = false;
}

void Entity::takeDamage(double amt, double armor) {
    double damage = amt * pow(0.95, armor);
    health -= damage;
    if(health <= 0) { isDead = true; }
}

void Entity::healDamage(double amt) {
    health += amt;
}

double Entity::getHealth() { return health; }
bool Entity::getDead() { return isDead; }