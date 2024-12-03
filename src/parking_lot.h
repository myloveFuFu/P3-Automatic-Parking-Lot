#ifndef PARKING_LOT_H
#define PARKING_LOT_H
#include <iostream> 
#include <vehicle.h>

class parking_slot {
    public:
        parking_slot();
        parking_slot(int size_type, int floor_number, int slot_number);
        ~parking_slot();
        bool park_vehicle(vehicle* vehicle); 
        // park the vehicle in the slot if succeeded return true, otherwise return false
        void remove_vehicle(); // remove the vehicle from the slot
        bool set_state( bool state ); // change the state of the is_empty attribute
        bool get_state(); // return the state of the is_empty attribute 
        int get_size_type();
        int get_floor_number();
        int get_slot_number();
    private:
        int size_type; // 1 for van and car, 2 for motorcycle and bicycle
        vehicle* parked_vehicle;
        int floor_number;
        int slot_number;
        bool is_empty;
};

class parking_lot {
    public: 
        parking_lot(int number_of_floors, int number_of_slots);
        // number_of_slots is the total number of slots in the parking lot
        // each floor's slot will be decided when generating the slot
        ~parking_lot();
        void print_parking_lot();
    private:
        parking_slot* generate_slots(int number_of_floors, int number_of_slots);
        int number_of_floors;
        int number_of_slots;
        parking_slot* slots;
} ;

#endif