#include "spear.h"

#include "animation.h"
#include "bleed.h"
#include "die.h"
#include "engine.h"
#include "entity.h"
#include "heal.h"
#include "hit.h"
#include "swing.h"

Spear::Spear(int damage)
: Item{"spear"}, damage{damage} {}

void Spear::use(Engine& engine, Entity& attacker, Entity& defender) {
//    engine.events.create_event<Hit>(defender, damage);
//    engine.events.create_event<Swing>(sprite, attacker.get_direction());
//    engine.events.create_event<Bleed>(defender, damage);

    Vec direction = defender.get_position() - attacker.get_position();

    auto swing = engine.events.create_event<Swing>(sprite, direction);
    std::shared_ptr<Event> gas = std::make_shared<Animation>("gas", defender.get_position());
    gas->add_next(Bleed{defender, damage});
    swing->add_next(gas);
}