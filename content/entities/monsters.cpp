#include "monsters.h"

#include "action.h"
#include "engine.h"
#include "entity.h"
#include "rest.h"
#include "randomness.h"
#include "wander.h"
#include "spiked_club.h"
#include "move.h"
#include "bite.h"

namespace Monsters {
void make_orc_masked(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("orc_masked");
    monster->set_max_health(10);
    // Monster bites you
    monster->add_to_inventory(std::make_shared<Bite>(2));
    monster->behavior = behavior;
}

void make_goblin(std::shared_ptr<Entity>& monster) {
    monster -> set_sprite("goblin");
    monster->set_max_health(5);

    monster->add_to_inventory(std::make_shared<Bite>(1));
    monster->behavior = behavior;
}

void make_ogre(std::shared_ptr<Entity>& monster) {
    monster -> set_sprite("ogre");
    monster->set_max_health(20);
    monster->behavior = behavior;
    monster->add_to_inventory(std::make_shared<Spiked_Club>(6));
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
