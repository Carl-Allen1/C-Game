#include "../headers/entity.hpp"
#include <cmath>

Entity::Entity() {}

Entity::Entity(double setHealth, double setArmor) {
    health = setHealth;
    armor = setArmor;
    isDead = false;
}

void Entity::takeDamage(double amt) {
    double damage = amt * pow(0.95, armor);
    health -= damage;
    if(health <= 0) { isDead = true; }
}

void Entity::healDamage(double amt) {
    health += amt;
}

void Entity::setArmor(double setArmor) { armor = setArmor; }

double Entity::getHealth() { return health; }
double Entity::getArmor() { return armor; }
bool Entity::getDead() { return isDead; }