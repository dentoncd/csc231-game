#include "attack.h"
#include "item.h"
#include "entity.h"

Attack::Attack(Entity& defender)
    : defender{defender} {}

Result Attack::perform(Engine& engine, std::shared_ptr<Entity> attacker) {
    // Get the attacker's weapon
    std::shared_ptr<Item> weapon = attacker->get_current_item();

    // Use the attacker's weapon on the defender
    weapon->use(engine, *attacker, defender);
    return success();
}

