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

std::string Ability::getDescription() const { return description; }
int Ability::getCooldown() const { return cooldown; }
int Ability::getCTracker() const { return cTracker; }
int Ability::getDuration() const { return duration; }
int Ability::getDTracker() const { return dTracker; }
bool Ability::getDurable() const { return durable; }
bool Ability::getUnlocked() const { return unlocked; }
bool Ability::getUsed() const { return used; }