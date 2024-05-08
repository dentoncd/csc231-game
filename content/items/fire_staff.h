#pragma once

#include "item.h"

class Fire_Staff : public Item {
public:
    explicit Fire_Staff(int damage);

    void use(Engine& engine, Entity& attacker, Entity& defender) override;
private:
    int damage;
};