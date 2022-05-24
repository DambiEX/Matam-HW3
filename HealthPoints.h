//TODO: errors and error codes. ctrl+f for שגיאה
//TODO: member parameters should start with 'm_'


#ifndef HW3_HEALTHPOINTS_H
#define HW3_HEALTHPOINTS_H

#define DEFAULT_HEALTH 100 //TODO: const int syntax
#define NEGATIVE -1
#define POSITIVE 1
#define InvalidArgument 1; //TODO: change to exact error code they asked for.

class HealthPoints{

public:
    HealthPoints(int max_health = DEFAULT_HEALTH);
    ~HealthPoints() = default;
    HealthPoints(const HealthPoints&) = default; //assignment constructor
    HealthPoints& operator=(const HealthPoints&) = default; // '=' operator

    explicit operator bool() const;

    HealthPoints& operator+=(int num);
    HealthPoints& operator-=(int num);

    //--------------comparison operators----------------//
    bool operator==(HealthPoints other) const;
    bool operator!=(HealthPoints other) const;
    bool operator>(HealthPoints other) const;
    bool operator<(HealthPoints other) const;
    bool operator<=(HealthPoints other) const;
    bool operator>=(HealthPoints other) const;

    //TODO: print operator
private:
    int max_health;
    int health;
};

HealthPoints operator+(HealthPoints health, int num);
HealthPoints operator-(HealthPoints health, int num);
//------wrong order operators just call the correct operators in the right order-----------//
HealthPoints operator+(int num, HealthPoints health);
HealthPoints operator-(const int num, const HealthPoints health); //TODO: clang tidy? const or not to const

#endif //HW3_HEALTHPOINTS_H
