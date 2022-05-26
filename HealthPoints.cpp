#include "HealthPoints.h"
#include <iostream>

static int withinBounds(int health, const int max_health){
    if (health < 0)
    {
        return 0;
    }
    else if (health > max_health)
    {
        return max_health;
    }
    else
        return health;
}

HealthPoints::HealthPoints(int max_health) : max_health(max_health), health(max_health) {
    if (max_health <= 0) {
        throw InvalidArgument();
    }
}

HealthPoints::operator bool() const {
    return health > 0;
}


//-------------------------------addition/subtraction operators----------------------------//
HealthPoints &HealthPoints::operator+=(const int num) {
    health = health+num;
    health = withinBounds(health, max_health);
    return *this;
}

HealthPoints &HealthPoints::operator-=(const int num) {
    health = health-num;
    health = withinBounds(health, max_health);
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

bool HealthPoints::operator!=(const HealthPoints other) const {
    return !(*this == other);
}

bool HealthPoints::operator>(const HealthPoints other) const {
    return this->health > other.health;
}

bool HealthPoints::operator<(const HealthPoints other) const {
    return this->health < other.health;
}

bool HealthPoints::operator<=(const HealthPoints other) const {
    return this->health <= other.health;
}

bool HealthPoints::operator>=(const HealthPoints other) const {
    return this->health >= other.health;
}

//----------------------print operator-----------------------------//

std::ostream &operator<<(std::ostream &os, HealthPoints current) {
    os << current.health << "(" << current.max_health << ")";
    return os;
}
