#include "sword.h"
#include "engine.h"
#include "hit.h"

Sword::Sword(int min_damage, int max_damage)
: Item{"sword"}, min_damage{min_damage}, max_damage{max_damage} {}

void Sword::use(Engine& engine, Entity&, Entity& defender) {
    engine.events.create_event<Hit>(defender, min_damage, max_damage);
}

