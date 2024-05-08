#pragma once

#include "event.h"
#include "vec.h"
#include "sprite.h"

class Entity;

class Raise : public Event {
public:
    Raise(Sprite& sprite, Vec direction);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Sprite copy;
    double delta;
    Vec direction;
};