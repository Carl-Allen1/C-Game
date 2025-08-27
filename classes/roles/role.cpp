#include "../headers/roles/role.hpp"

Role::Role() {}

Role::Role(int spc, int spt, int ssc, int sst, int suc, int sut, int setAttacks) {
    primCooldown = spc;
    primTracker = spt;
    secCooldown = ssc;
    secTracker = sst;
    ultCooldown = suc;
    ultTracker = sut;

    attacks = setAttacks;

    secUnlocked = false;
    ultUnlocked = false;
}

void Role::setPrimCooldown(int setPrimCooldown) { primCooldown = setPrimCooldown; }
void Role::setPrimTracker(int setPrimTracker) { primTracker = setPrimTracker; }

void Role::setSecUnlocked(bool setSecUnlocked) { secUnlocked = setSecUnlocked; }
void Role::setSecCooldown(int setSecCooldown) { secCooldown = setSecCooldown; }
void Role::setSecTracker(int setSecTracker) { secTracker = setSecTracker; }

void Role::setUltUnlocked(bool setUltUnlocked) { ultUnlocked = setUltUnlocked; }
void Role::setUltCooldown(int setUltCooldown) { ultCooldown = setUltCooldown; }
void Role::setUltTracker(int setUltTracker) { ultTracker = setUltTracker; }

void Role::setAttacks(int setAttacks) { attacks = setAttacks; }

int Role::getPrimCooldown() { return primCooldown; }
int Role::getPrimTracker() { return primTracker; }

bool Role::getSecUnlocked() { return secUnlocked; }
int Role::getSecCooldown() { return secCooldown; }
int Role::getSecTracker() { return secTracker; }

bool Role::getUltUnlocked() { return ultUnlocked; }
int Role::getUltCooldown() { return ultCooldown; }
int Role::getUltTracker() { return ultTracker; }

int Role::getAttacks() { return attacks; }