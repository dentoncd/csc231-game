#include "opendoor.h"
#include "door.h"
#include "engine.h"
#include "updatefov.h"
#include "action.h"
#include "entity.h"

Result OpenDoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
        door.open();
        engine.events.create_event<UpdateFOV>();
        return success();
}
OpenDoor::OpenDoor(Door& door)
: door{door} {}
