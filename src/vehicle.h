#ifndef VECHICLE_H
#define VECHICLE_H
class Vehicle {
    public:
    Vehicle();
    int get_type();
    double get_arrival_time();
    protected:
    int type; // 0 for van, 1 for car, 2 for motorcycle, 3 for bicycle
    double arrival_time; // arrival time of the vehicle
    // the basic design is that if the vehicle is created before the parking lot is created 
    // then the arrival time is set to be minus number
};

class Van: public Vehicle {
    public:
    Van();
    Van(double arr_time);
};

class Car: public Vehicle {
    public:
    Car();
    Car(double arr_time);
};

class Motorcycle: public Vehicle {
    public:
    Motorcycle();
    Motorcycle(double arr_time);
};

class Bicycle: public Vehicle {
    public:
    Bicycle();
    Bicycle(double arr_time);
};

#endif