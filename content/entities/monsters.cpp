#include "monsters.h"

#include "action.h"
#include "engine.h"
#include "entity.h"
#include "rest.h"
#include "randomness.h"
#include "wander.h"
#include "move.h"

namespace Monsters {
void make_orc_masked(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("orc_masked");
    monster->set_max_health(5);
    monster->behavior = behavior;
}

std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
    // pursue Hero if monster can see him (If Hero sees me, I see him)
    if (entity.is_visible() && engine.hero) {
        auto path =
            engine.dungeon.calculate_path(entity.get_position(), engine.hero->get_position());
        if (path.size() > 1) {
            auto direction = path.at(1) - path.at(0);
            return std::make_unique<Move>(direction);
        }
    }
    // Monster doesn't see Hero
    if (probability(66)) {
        return std::make_unique<Wander>();
    } else {
        return std::make_unique<Rest>();
    }
}
}
