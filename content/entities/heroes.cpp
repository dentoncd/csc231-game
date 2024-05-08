#include "heroes.h"
#include "entity.h"
#include "action.h"
#include "engine.h"
#include "move.h"
#include "rest.h"
#include "closedoor.h"
#include "sword.h"
#include "item.h"
#include "spear.h"
#include "potion_red.h"
#include "heal.h"
#include "fire_staff.h"
#include <ctime>

namespace Heroes {
void make_wizard(std::shared_ptr<Entity>& hero) {
    hero->set_sprite("wizard");
    hero->set_max_health(100);
    hero->add_to_inventory(std::make_shared<Sword>(5));
    hero->add_to_inventory(std::make_shared<Spear>(3));
    hero->add_to_inventory(std::make_shared<Potion_Red>(5));
    hero->add_to_inventory(std::make_shared<Fire_Staff>(2));
    hero->behavior = behavior;
}

std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
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

    else if (!key.empty() && std::isdigit(key.at(0))){
        int item_num = std::stoi(key) - 1; // "1" -> index 0
        entity.select_item(item_num);
    }

    return nullptr;
}
}
