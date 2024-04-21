#include "hit.h"
#include "entity.h"
#include "die.h"

Hit::Hit(Entity& entity, int min_damage, int max_damage)
    : entity{entity} {}

void Hit::execute(Engine&) {
    entity.take_damage(damage);
}

void Hit::when_done(Engine&) {
    if (!entity.is_alive()) {
        add_next(Die(entity));
    }
}