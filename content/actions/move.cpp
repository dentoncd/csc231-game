#include "move.h"
#include "entity.h"
#include "tile.h"
#include "engine.h"
#include "action.h"
//#include "opendoor.h"

Move::Move(Vec direction) : direction(direction) {

}
Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position() + direction;
    entity->change_direction(direction);
    Tile& tile = engine.dungeon.get_tile(position);

    if (tile.is_wall() || tile.has_entity()) {
        return failure();
    }

    if (tile.has_door()) {
       // return alternative(OpenDoor{*tile.door})
    }


    entity->move_to(position);
    return success();

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