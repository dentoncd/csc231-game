#include "rest.h"
#include <iostream>

Result Rest::perform(Engine&, std::shared_ptr<Entity>) {
    std::cout << "ZZZZZZZZZZ\n";
    return success();
}
