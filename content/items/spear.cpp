#include "spear.h"
#include "hit.h"
#include "engine.h"
#include "swing.h"
#include "entity.h"
#include "bleed.h"
#include "heal.h"
#include "die.h"


Spear::Spear(int damage)
: Item{"spear"}, damage{damage} {}

void Spear::use(Engine& engine, Entity& attacker, Entity& defender) {
//    engine.events.create_event<Hit>(defender, damage);
    engine.events.create_event<Swing>(sprite, attacker.get_direction());
    engine.events.create_event<Bleed>(defender, damage);
}