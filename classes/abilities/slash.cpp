#include "../headers/abilities/slash.hpp"
#include "../headers/color.hpp"
#include "../headers/player.hpp"
#include "../headers/enemy.hpp"
#include <iostream>

Slash::Slash() {}

Slash::Slash(int cooldown, bool durable, bool unlocked, int damage) {
    this->description = "Slashes an enemy for " + std::to_string(damage) + " damage!";
    this->cooldown = cooldown;
    this->durable = durable;
    this->unlocked = unlocked;
    this->damage = damage;
}

void Slash::execute(GameContext gctx) {
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

    gctx.enemies->front().takeDamage(damage, 0);
}