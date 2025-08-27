#include "../headers/enemy.hpp"

Enemy::Enemy() {}

Enemy::Enemy(double setDamage, double setHealth) {
    damage = setDamage;
    health = setHealth;
}

void Enemy::setDamage(double setDamage) { damage = setDamage; }

double Enemy::getDamage() { return damage; }