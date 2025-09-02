#ifndef ABILITY_H
#define ABILITY_H

#include "../gamecontext.hpp"
#include <string>

class Ability {
protected:
    std::string description;

    int cooldown;
    int cTracker;
    int duration;
    int dTracker;

    bool durable;
    bool unlocked;
    bool used;
public:
    virtual ~Ability() = default;
    virtual void execute(GameContext gctx) { }
    virtual void revert(GameContext gctx) { }

    virtual void incCTracker();
    virtual void incDTracker();

    virtual void setCooldown(int cooldown);
    virtual void setCTracker(int cTracker);
    virtual void setDuration(int duration);
    virtual void setDTracker(int dTracker);
    virtual void setDurable(bool durable);
    virtual void setUnlocked(bool unlocked);
    virtual void setUsed(bool used);

    virtual std::string getDescription() const;
    virtual int getCooldown() const;
    virtual int getCTracker() const;
    virtual int getDuration() const;
    virtual int getDTracker() const;
    virtual bool getDurable() const;
    virtual bool getUnlocked() const;
    virtual bool getUsed() const;
};

#endif // ABILITY_H