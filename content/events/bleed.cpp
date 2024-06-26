#include "bleed.h"
#include "entity.h"
#include "engine.h"
#include <cmath>
#include "die.h"

constexpr int duration = 4;
constexpr int delta = 8;

Bleed::Bleed(Entity& entity, int damage)
: Event{duration}, entity{entity}, damage{damage}, remaining_duration{remaining_duration} {

}

void Bleed::execute(Engine& ) {
    if (remaining_duration > 0) {
        entity.take_damage(damage);
        remaining_duration -= delta;

    }
}

void Bleed::when_done(Engine& ) {
    if (!entity.is_alive()) {
        add_next(Die(entity));
    }
}


