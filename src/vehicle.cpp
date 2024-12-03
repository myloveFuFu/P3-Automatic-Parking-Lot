#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle() {
    type = -1;
    arrival_time = -1; // which is meaningless
    std::cout << "Meaningless Vehicle created" << std::endl;
}

int Vehicle::get_type() {
    return type;
}

double Vehicle::get_arrival_time() {
    return arrival_time;
}

Van::Van() {
    type = 0;
    arrival_time = 0; // should be set 
}

Van::Van(double arr_time) {
    type = 0;
    arrival_time = arr_time;
}

Car::Car() {
    type = 1;
    arrival_time = 0; // should be set 
}

Car::Car(double arr_time) {
    type = 1;
    arrival_time = arr_time;
}

Motorcycle::Motorcycle() {
    type = 2;
    arrival_time = 0; // should be set 
}

Motorcycle::Motorcycle(double arr_time) {
    type = 2;
    arrival_time = arr_time;
}

Bicycle::Bicycle() {
    type = 3;
    arrival_time = 0; // should be set 
}

Bicycle::Bicycle(double arr_time) {
    type = 3;
    arrival_time = arr_time;
}
