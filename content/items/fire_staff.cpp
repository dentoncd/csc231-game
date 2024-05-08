#include "fire_staff.h"
#include "hit.h"
#include "engine.h"
#include "swing.h"
#include "entity.h"
#include "raise.h"
#include "animation.h"
#include "sound.h"

Fire_Staff::Fire_Staff(int damage)
: Item{"staff_red"}, damage{damage} {}

void Fire_Staff::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();

    auto raise = engine.events.create_event<Raise>(sprite, direction);
    std::shared_ptr<Event> fire = std::make_shared<Animation>("fire", defender.get_position());
    fire->add_next(Hit{defender, damage});
    raise->add_next(fire);
    engine.events.create_event<Sound>("fire");
}