#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include "player.hpp"
#include "enemy.hpp"
#include "gamecontext.hpp"

class Main {
private:
    bool started;
    Player player;
    GameContext gctx;
    std::vector<Enemy> enemies;
public:
    Main(double playerHealth);
    void generateEnemies(int minHealth, int maxHealth, int minDamage, int maxDamage, int amt);
    void runGame();

    void pickRole();
    void pickWeapon();

    void attack();
    void useAbilities();
    void incAbilities();
    void getAttacked();

    void gameOver();
};

#endif // MAIN_H