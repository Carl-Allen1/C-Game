#include "../headers/abilities/ability.hpp"

void Ability::incCTracker() { cTracker++; }
void Ability::incDTracker() { dTracker++; }

void Ability::setCooldown(int cooldown) { this->cooldown = cooldown; }
void Ability::setCTracker(int cTracker) { this->cTracker = cTracker; }
void Ability::setDuration(int duration) { this->duration = duration; }
void Ability::setDTracker(int dTracker) { this->dTracker = dTracker; }
void Ability::setDurable(bool durable) { this->durable = durable; }
void Ability::setUnlocked(bool unlocked) { this->unlocked = unlocked; }
void Ability::setUsed(bool used) { this->used = used; }

std::string Ability::getDescription() { return description; }
int Ability::getCooldown() { return cooldown; }
int Ability::getCTracker() { return cTracker; }
int Ability::getDuration() { return duration; }
int Ability::getDTracker() { return dTracker; }
bool Ability::getDurable() { return durable; }
bool Ability::getUnlocked() { return unlocked; }
bool Ability::getUsed() { return used; }