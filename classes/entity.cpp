#include "../headers/entity.hpp"
#include <cmath>

Entity::Entity() {}

Entity::Entity(double health) {
    this->health = health;
    this->isDead = false;
}

void Entity::takeDamage(double amt, double armor) {
    double damage = amt * pow(0.95, armor);
    health -= damage;
    if(health <= 0) { isDead = true; }
}

void Entity::healDamage(double amt) {
    health += amt;
}

void Entity::setDead(bool isDead) { this->isDead = isDead; }

double Entity::getHealth() { return health; }
bool Entity::getDead() const { return isDead; }