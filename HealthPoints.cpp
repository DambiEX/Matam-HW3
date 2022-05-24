//TODO: pass by reference instead? afte watching lectures and tutorial

#include "HealthPoints.h"
#include <iostream>

static int fill(const int threshold, const int attribute, const int amount, int negativity) {
    /*
     * Fills up to a certain threshold. Or empties an int down to 0, depending on negativity.
     */
    if (amount <= 0) {
        return attribute;
    }
    int change = amount * negativity;
    if ((attribute + change) * negativity > threshold) {
        return threshold;
    } else {
        return attribute + change;
    }
}

HealthPoints::HealthPoints(int max_health) : max_health(max_health), health(max_health) {
    if (max_health <= 0) {
        throw HealthPoints::InvalidArgument();
    }
}

HealthPoints::operator bool() const {
    return health > 0;
}


//-------------------------------addition/subtraction operators----------------------------//
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

HealthPoints operator-(const HealthPoints health, const int num) {
    return HealthPoints(health) -= num;
}

//------wrong order operators just call the correct operators in the right order-----------//
HealthPoints operator+(const int num, const HealthPoints health) {
    return health + num;
}

HealthPoints operator-(const int num, const HealthPoints health) {
    return health + num;
}


//----------------------comparison operators-----------------------------//
bool HealthPoints::operator==(const HealthPoints other) const {
    if (this->health == other.health) {
        return true;
    } else {
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

//----------------------print operator-----------------------------//

std::ostream &operator<<(std::ostream &os, HealthPoints current) {
    os << current.health << "(" << current.max_health << ")";
    return os;
}
