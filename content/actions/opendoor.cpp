#include "opendoor.h"
#include "door.h"
#include "engine.h"
#include "updatefov.h"
#include "action.h"
#include "entity.h"
#include "sound.h"

Result OpenDoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
        door.open();
        engine.events.create_event<UpdateFOV>();
        engine.events.create_event<Sound>("door-open");
        return success();
}
OpenDoor::OpenDoor(Door& door)
: door{door} {}
