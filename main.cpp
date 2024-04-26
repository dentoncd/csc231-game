#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        // Customize character
        Heroes::make_wizard(hero);

        for (int i = 0; i < 10; ++i) {
            std::shared_ptr<Entity> monster1 = engine.create_monster();
            std::shared_ptr<Entity> monster2 = engine.create_monster();
            std::shared_ptr<Entity> monster3 = engine.create_monster();

            Monsters::make_orc_masked(monster1);
            Monsters::make_ogre(monster2);
            Monsters::make_goblin(monster3);
        }

        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
