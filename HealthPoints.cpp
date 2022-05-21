//TODO: pass by reference instead? afte watching lectures and tutorial

#include "HealthPoints.h"

static int fill(const int threshold, const int attribute, const int amount, int negativity) {
    if(amount <= 0)
    {
        return attribute;
    }
    int change = amount * negativity;
    if ((attribute + change) * negativity > threshold)
    {
        return threshold;
    } else
    {
        return attribute + change;
    }
}

HealthPoints::HealthPoints(int max_health) : max_health(max_health), health(max_health)
{ //TODO: return correct error on negative input.
    if (max_health < 0){
        throw InvalidArgument;
        //throw HealthPoints::InvalidArgument; //TODO: syntax
    }
}

HealthPoints::operator bool() const {
    return health > 0;
}

HealthPoints &HealthPoints::operator+=(const int num) {
    health = fill(max_health, health, num, POSITIVE);
    return *this;
}

HealthPoints &HealthPoints::operator-=(const int num) {
    health = fill(0, health, num, NEGATIVE);
    return *this;
}

HealthPoints operator+(const HealthPoints health, const int num) {
    return HealthPoints(health) += num;
}

HealthPoints operator+(const int num, const HealthPoints health) {
    return health + num;
}

HealthPoints operator-(const HealthPoints health, const int num) {
    return HealthPoints(health) -= num;
}

HealthPoints operator-(const int num, const HealthPoints health) {
    return health + num;
}

bool HealthPoints::operator==(const HealthPoints other) const {
    if(this->health == other.health)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool HealthPoints::operator!=(HealthPoints other) const {
    return !(*this == other);
}

bool HealthPoints::operator>(HealthPoints other) const {
    return this->health > other.health;
}

bool HealthPoints::operator<(HealthPoints other) const {
    return this->health < other.health;
}

bool HealthPoints::operator<=(HealthPoints other) const {
    return this->health <= other.health;
}

bool HealthPoints::operator>=(HealthPoints other) const {
    return this->health >= other.health;
}

