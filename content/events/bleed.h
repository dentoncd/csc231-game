#pragma once

#include "event.h"
#include "sprite.h"

class Entity;

class Bleed : public Event {
public:
    Bleed(Entity& entity, int damage);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Entity& entity;
    int damage;
    int remaining_duration;
};