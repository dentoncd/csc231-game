#include "fire.h"
#include "engine.h"

Fire::Fire(Vec position)
:position{position} {}

void Fire::execute(Engine& engine) {
    if (frame_count == 0) { // Event::frame_count
        sprite = engine.graphics.get_animated_sprite("fire", 1);

        // Event::number_of_frames matches the animation number of frames
        number_of_frames = sprite.number_of_frames();

    }
    engine.camera.add_overlay(position, sprite.get_sprite());
    sprite.update(); // moves to next frame
}