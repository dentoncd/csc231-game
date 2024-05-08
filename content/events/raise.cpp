#include "raise.h"
#include <cmath>

constexpr int duration = 3;
constexpr int delta = 7;

Raise::Raise(Sprite& sprite, Vec direction)
:Event{duration}, sprite{sprite}, copy{sprite} {
    sprite.center = sprite.size / 2;
    sprite.shift.y -= sprite.size.y / 4;
    sprite.angle = 0;

    // Thrust but like a little different
    if (direction == Vec{1,0}) { // right
        sprite.shift.y += sprite.size.y / 2;
        sprite.angle = 90;
    }
    else if (direction  == Vec{-1,0}) { // left
        sprite.shift.y += sprite.size.y / 2;
        sprite.angle = -90;
    }
    else if (direction == Vec{0, 1}) { // up
        sprite.angle = 0;
        this->direction = -1 * direction;
    }

    else  { // down
        sprite.angle = 180;
        sprite.shift.y += sprite.size.y;
        this->direction = -1 * direction;

    }
}

void Raise::execute(Engine& engine) {
    direction = {0,1};
    sprite.shift += direction * delta;
}

void Raise::when_done(Engine& engine) {
    sprite = copy;
}