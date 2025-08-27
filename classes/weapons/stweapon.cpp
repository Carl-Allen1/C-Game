#include "../headers/weapons/stweapon.hpp"

STWeapon::STWeapon() {}

void STWeapon::attack(std::vector<Enemy> targets) {
    targets.front().takeDamage(strength, 0);
}