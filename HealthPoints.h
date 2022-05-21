//TODO: errors and error codes. ctrl+f for שגיאה


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
    //HealthPoints&() = default; //TODO: copy ctor syntax
    HealthPoints& operator=(const HealthPoints&) = default;

    explicit operator bool() const;

    HealthPoints& operator+=(const int num);
    HealthPoints& operator-=(const int num);



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

HealthPoints operator+(const HealthPoints health, const int num);
HealthPoints operator-(const HealthPoints health, const int num);
//-------------operators in the wrong order just call operators in the right order-----------//
HealthPoints operator+(const int num, const HealthPoints health);
HealthPoints operator-(const int num, const HealthPoints health);

#endif //HW3_HEALTHPOINTS_H
