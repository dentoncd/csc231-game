#include "heal.h"
#include "entity.h"

Heal::Heal(Entity& entity, int healing_amount)
:entity {entity}, healing_amount{healing_amount} {}

void Heal::execute(Engine& ) {
    entity.heal_health(healing_amount);
}

void Heal::when_done(Engine& ) {
    remove("potion_red");
}
