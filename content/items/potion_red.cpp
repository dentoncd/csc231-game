#include "potion_red.h"
#include "engine.h"
#include "entity.h"
#include "swing.h"
#include "heal.h"

Potion_Red::Potion_Red(int healing_amount)
    : Item{"potion_red"}, healing_amount{healing_amount} {}

void Potion_Red::use(Engine& engine, Entity& attacker, Entity& ) {
    engine.events.create_event<Heal>(attacker, healing_amount);
    engine.events.create_event<Swing>(sprite, attacker.get_direction());

}