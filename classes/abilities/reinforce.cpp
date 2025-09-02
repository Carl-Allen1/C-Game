#include "../headers/abilities/reinforce.hpp"
#include "../headers/color.hpp"
#include "../headers/player.hpp"
#include "../headers/enemy.hpp"
#include <iostream>

Reinforce::Reinforce() {}

Reinforce::Reinforce(int cooldown, int duration, bool durable, bool unlocked, double increase) {
    this->description = "Increases armor by " + std::to_string(increase) + " for a short time";
    this->cooldown = cooldown;
    this->durable = durable;
    this->duration = duration;
    this->unlocked = unlocked;
    this->increase = increase;
}

void Reinforce::execute(GameContext gctx) {
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

    double origArmor = gctx.player->getRole()->getArmor();
    gctx.player->getRole()->setArmor(origArmor * increase);
}

void Reinforce::revert(GameContext gctx) {
    double changedArmor = gctx.player->getRole()->getArmor();
    gctx.player->getRole()->setArmor(changedArmor / increase);
}