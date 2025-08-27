#ifndef ROLE_H
#define ROLE_H

class Role {
protected:
    int attacks;

    int primCooldown;
    int primTracker;
    bool secUnlocked;
    int secCooldown;
    int secTracker;
    bool ultUnlocked;
    int ultCooldown;
    int ultTracker;
public:
    enum class Type {
        Any,
        Fighter
    };

    Role();
    Role(int spc, int spt, int ssc, int sst, int suc, int sut, int setAttacks);

    virtual void usePrimary() = 0;
    virtual void useSecondary() = 0;
    virtual void useUltimate() = 0;
    virtual Type type() = 0;
    virtual bool hasArmor() = 0;

    void setAttacks(int setAttacks);

    void setPrimCooldown(int setPrimCooldown);
    void setPrimTracker(int setPrimTracker);

    void setSecUnlocked(bool setSecUnlocked);
    void setSecCooldown(int setSecCooldown);
    void setSecTracker(int setSecTracker);

    void setUltUnlocked(bool setUltUnlocked);
    void setUltCooldown(int setUltCooldown);
    void setUltTracker(int setUltTracker);

    int getAttacks();

    int getPrimCooldown();
    int getPrimTracker();

    bool getSecUnlocked(); 
    int getSecCooldown();
    int getSecTracker();

    bool getUltUnlocked();
    int getUltCooldown();
    int getUltTracker();
};

#endif // ROLE_H