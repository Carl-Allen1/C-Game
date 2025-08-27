#ifndef ROLE_H
#define ROLE_H

class Role {
protected:
    int primCooldown;
    int primTracker;
    int secCooldown;
    int secTracker;
    int ultCooldown;
    int ultTracker;
public:
    Role();
    Role(int spc, int spt, int ssc, int sst, int suc, int sut);
    virtual void usePrimary() = 0;
    virtual void useSecondary() = 0;
    virtual void useUltimate() = 0;
    void setPrimCooldown(int setPrimCooldown);
    void setPrimTracker(int setPrimTracker);
    void setSecCooldown(int setSecCooldown);
    void setSecTracker(int setSecTracker);
    void setUltCooldown(int setUltCooldown);
    void setUltTracker(int setUltTracker);
    int getPrimCooldown();
    int getPrimTracker();
    int getSecCooldown();
    int getSecTracker();
    int getUltCooldown();
    int getUltTracker();
};

#endif // ROLE_H