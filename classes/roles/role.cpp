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
}

void Role::setPrimCooldown(int setPrimCooldown) { primCooldown = setPrimCooldown; }
void Role::setPrimTracker(int setPrimTracker) { primTracker = setPrimTracker; }
void Role::setSecCooldown(int setSecCooldown) { secCooldown = setSecCooldown; }
void Role::setSecTracker(int setSecTracker) { secTracker = setSecTracker; }
void Role::setUltCooldown(int setUltCooldown) { ultCooldown = setUltCooldown; }
void Role::setUltTracker(int setUltTracker) { ultTracker = setUltTracker; }

int Role::getPrimCooldown() { return primCooldown; }
int Role::getPrimTracker() { return primTracker; }
int Role::getSecCooldown() { return secCooldown; }
int Role::getSecTracker() { return secTracker; }
int Role::getUltCooldown() { return ultCooldown; }
int Role::getUltTracker() { return ultTracker; }