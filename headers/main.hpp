#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include "player.hpp"
#include "enemy.hpp"

class Main {
private:
    bool started;
    Player player;
    std::vector<Enemy> enemies;
public:
    Main(double playerHealth);
    void generateEnemies(int minHealth, int maxHealth, int minDamage, int maxDamage, int amt);
    void runGame();
    void pickStarter();
    void attack();
    void getAttacked();
    void gameOver();
};

#endif // MAIN_H