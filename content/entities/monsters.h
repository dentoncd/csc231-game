#pragma once
#include <memory>
#include "entity.h"

namespace Monsters {
    void make_orc_masked(std::shared_ptr<Entity>& monster);
    void make_goblin(std::shared_ptr<Entity>& monster);
    void make_ogre(std::shared_ptr<Entity>& monster);

    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity);

}
