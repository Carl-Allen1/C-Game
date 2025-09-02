#include "../headers/enemy.hpp"

Enemy::Enemy() {}

Enemy::Enemy(double damage, double health) {
    this->damage = damage;
    this->health = health;
}

void Enemy::setDamage(double damage) { this->damage = damage; }

double Enemy::getDamage() const { return damage; }