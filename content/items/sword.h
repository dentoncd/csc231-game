#pragma once

#include "item.h"

class Sword : public Item {
public:
    explicit Sword(int min_damage, int max_damage);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int min_damage;
    int max_damage;
};