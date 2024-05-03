#pragma once
#include "event.h"

class Entity;

class Heal : public Event {
public:
    Heal(Entity& entity, int healing_amount);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Entity& entity;
    int healing_amount;
};