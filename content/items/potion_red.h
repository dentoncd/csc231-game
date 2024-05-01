#pragma once
#include "item.h"

class Potion_Red : public Item {
public:
    explicit Potion_Red(int healing_amount);

    // add health to owner
    void use(Engine& engine, Entity& owner) override;
private:
    int healing_amount;
};