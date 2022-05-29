#include <iostream>

#ifndef HW3_HEALTHPOINTS_H
#define HW3_HEALTHPOINTS_H

class HealthPoints {

public:
    class InvalidArgument {
    };

    static const int DEFAULT_HEALTH = 100, NEGATIVE = -1, POSITIVE = 1;

    HealthPoints(int max_health = DEFAULT_HEALTH); //non-explicit on purpose.
    HealthPoints(const HealthPoints &) = default; //assignment constructor
    HealthPoints &operator=(const HealthPoints &) = default; // '=' operator
    ~HealthPoints() = default;

    explicit operator bool() const;

    HealthPoints &operator+=(int num);

    HealthPoints &operator-=(int num);

    //--------------comparison operators----------------//
    bool operator==(HealthPoints other) const;

    bool operator==(int num) const;

    bool operator!=(HealthPoints other) const;

    bool operator>(HealthPoints other) const;

    bool operator<(HealthPoints other) const;

    bool operator<=(HealthPoints other) const;

    bool operator>=(HealthPoints other) const;

    //print operator:
    friend std::ostream &operator<<(std::ostream &os, HealthPoints current);

private:
    int max_health;
    int health;
};

HealthPoints operator+(HealthPoints health, int num);

HealthPoints operator-(HealthPoints health, int num);

//------wrong order operators just call the correct operators in the right order-----------//
HealthPoints operator+(int num, HealthPoints health);

HealthPoints operator-(int num, HealthPoints health);

HealthPoints operator==(int num, HealthPoints health);

#endif //HW3_HEALTHPOINTS_H
