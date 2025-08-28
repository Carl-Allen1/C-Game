#ifndef FIGHTER_H
#define FIGHTER_H

#include "role.hpp"

class Fighter: public Role {
private:
    double armor;
    int secDuration;
    bool ultUsed;
public:
    Fighter();
    Fighter(double setArmor, int setSecDuration);

    void usePrimary() override; // Placeholder for compilation
    double usePrimary(double damage); // This takes place of the same in Role.hpp/cpp but cannot be named so due to changed params
    void useSecondary() override;
    void useUltimate() override;
    Role::Type type() override;
    bool hasArmor() override;

    void setArmor(double setArmor);
    void setSecDuration(int setSecDuration);
    void setUltUsed(bool setUltUsed);

    double getArmor();
    int getSecDuration();
    bool getUltUsed();
};

#endif // FIGHTER_H