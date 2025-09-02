#include "../headers/abilities/frenzy.hpp"
#include "../headers/color.hpp"
#include "../headers/player.hpp"
#include "../headers/enemy.hpp"
#include <iostream>

Frenzy::Frenzy() {}

Frenzy::Frenzy(int cooldown, int duration, bool durable, bool unlocked, int increase) {
    this->description = "Multiplies enemies targeted by " + std::to_string(increase) + " for a short time!";
    this->cooldown = cooldown;
    this->durable = durable;
    this->duration = duration;
    this->unlocked = unlocked;
    this->increase = increase;
}

void Frenzy::execute(GameContext gctx) {
    if(!unlocked) {
        std::cout << Color::colorCodes[Color::Colors::BrightRed] << "Ability not unlocked!"
            << Color::colorCodes[Color::Colors::Reset] << std::endl;
        return;
    }
    
    if(getUsed()) {
        std::cout << Color::colorCodes[Color::Colors::BrightRed] << "Ability on cooldown!"
            << Color::colorCodes[Color::Colors::Reset] << std::endl;
        return;
    }

    int origTargets = gctx.player->getRole()->getAttacks();
    gctx.player->getRole()->setAttacks(origTargets * increase);
}

void Frenzy::revert(GameContext gctx) {
    int changedTargets = gctx.player->getRole()->getAttacks();
    gctx.player->getRole()->setAttacks(changedTargets / increase);
}