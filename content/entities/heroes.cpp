#include "heroes.h"
#include "entity.h"
#include "action.h"
#include "engine.h"
#include "move.h"
#include "rest.h"
#include "closedoor.h"
#include "opendoor.h"
#include "sword.h"
#include <ctime>

namespace Heroes {
void make_wizard(std::shared_ptr<Entity>& hero) {
    hero->set_sprite("wizard");
    hero->set_max_health(10);
    hero->add_to_inventory(std::make_shared<Sword>(2, 5));
    hero->behavior = behavior;
}

std::unique_ptr<Action> behavior(Engine& engine, Entity& ) {
    std::string key = engine.input.get_last_keypress();
    if (key == "R") {
        return std::make_unique<Rest>();
    }
    else if (key == "C") {
        return std::make_unique<CloseDoor>();
    }

    else if (key == "Up" || key == "W") {
        return std::make_unique<Move>(Vec{0, 1});
    }
    else if (key == "Down") {
        return std::make_unique<Move>(Vec{0, -1});
    }
    else if (key == "Left") {
        return std::make_unique<Move>(Vec{-1, 0});
    }
    else if (key == "Right") {
        return std::make_unique<Move>(Vec{1, 0});
    }

    return nullptr;
}
}
