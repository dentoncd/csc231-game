#include "spiked_club.h"
#include "entity.h"
#include "swing.h"
#include "engine.h"
#include "hit.h"

Spiked_Club::Spiked_Club(int damage)
: Item{"spiked_club"}, damage{damage} {}

void Spiked_Club::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Swing>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}