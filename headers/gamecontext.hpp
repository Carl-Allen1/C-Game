#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H

#include <vector>

class Player;
class Enemy;

struct GameContext {
    Player* player;
    std::vector<Enemy>* enemies;
};

#endif // GAME_CONTEXT_H