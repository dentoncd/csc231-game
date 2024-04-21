#pragma once
#include <memory>
#include "entity.h"

namespace Monsters {
    void make_orc_masked(std::shared_ptr<Entity>& monster);

    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity);

}
