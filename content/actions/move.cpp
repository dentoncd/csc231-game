#include "move.h"

#include "action.h"
#include "attack.h"
#include "engine.h"
#include "entity.h"
#include "opendoor.h"
#include "rest.h"
#include "tile.h"

Move::Move(Vec direction)
    : direction{direction} {}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->change_direction(direction);

    Vec position = entity->get_position() + direction;
    Tile& tile = engine.dungeon.get_tile(position);

    if (tile.is_wall()) { // update is_wall
        return failure();
    }

    if (tile.has_entity()) {
        if (entity->get_team() != tile.entity->get_team()) {
            return alternative(Attack(*tile.entity));
        }
        else {
            return alternative(Rest{});
        }
    }

    if (tile.has_door() && !tile.door->is_open()) {
        return alternative(OpenDoor{*tile.door});

    }

    else {
        entity->move_to(position);
        return success();
    }



}



/* Dereference the pointer thingy by using
     * obj = *ptr is the same as ptr = &obj
     *
     * Also, if wall or entity -> failure (turn is not possible
     * try again)
     *
     * If door is there, alt(OpenDoor{*tile.door})
     *
     * If tile is empty, then you are successful and the turn is done
 */