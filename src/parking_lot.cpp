#include "parking_lot.h"
// class parking_slot {
//     public:
//         parking_slot();
//         parking_slot(int size_type, int floor_number, int slot_number);
//         ~parking_slot();
//         bool park_vehicle(vehicle* vehicle); // park the vehicle in the slot
//         void remove_vehicle(); // remove the vehicle from the slot
//         bool set_state(); // change the state of the is_empty attribute
//         bool get_state(); // return the state of the is_empty attribute 
//         int get_size_type();
//         int get_floor_number();
//         int get_slot_number();
//     private:
//         int size_type; // 1 for van and car, 2 for motorcycle and bicycle
//         vehicle* parked_vehicle;
//         int floor_number;
//         int slot_number;
//         bool is_empty;
// };
parking_slot::parking_slot() {
    this->size_type = 0;
    this->floor_number = 0;
    this->slot_number = 0;
    this->is_empty = true;
    this->parked_vehicle = new vehicle();
    if( this->parked_vehicle == NULL) {
        std::cerr << "Error: Memory allocation failed\n";
        exit(-1); 
    }    
}

parking_slot::parking_slot(int size_type, int floor_number, int slot_number) {
    this->size_type = size_type;
    this->floor_number = floor_number;
    this->slot_number = slot_number;
    this->is_empty = true;
    this->parked_vehicle = new vehicle();
    if( this->parked_vehicle == NULL) {
        std::cerr << "Error: Memory allocation failed\n";
        exit(-1); 
    }    
}

parking_slot::~parking_slot() {
    delete parked_vehicle;
}

