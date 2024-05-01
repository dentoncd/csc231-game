#include "potion_red.h"
#include "engine.h"
#include "entity.h"

Potion_Red::Potion_Red(int healing_amount)
    : Item{"potion_red"}, healing_amount{healing_amount} {}

void Potion_Red::use(Engine& engine, Entity& owner) {
    
}