#include "parking_lot.h"
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

bool parking_slot::park_vehicle(vehicle* vehicle) {
    if( this->is_empty == false) {
        return false;
    }
    this->parked_vehicle = vehicle;
    this->is_empty = false;
    return true;
}

void parking_slot::remove_vehicle() {
    this->is_empty = true;
    this->parked_vehicle = NULL;
}

bool parking_slot::set_state( bool state ) {
    this->is_empty = state;
    return true;
}

bool parking_slot::get_state() {
    return this->is_empty;
}

int parking_slot::get_size_type() {
    return this->size_type;
}   

int parking_slot::get_floor_number() {
    return this->floor_number;
}

int parking_slot::get_slot_number() {
    return this->slot_number;
}

void parking_slot::print_parking_slot() { 
    std::cout << "Floor number: " << this->floor_number << ', '
                << "Slot number: " << this->slot_number << ', '
                << "Size type: " << this->size_type << ', '
                << "Is empty: " << this->is_empty << '\n';
}

parking_lot::parking_lot(int number_of_floors, int number_of_slots) {
    this->number_of_floors = number_of_floors;
    this->number_of_slots = number_of_slots;
    this->slots = new parking_slot[number_of_slots];
    if( this->slots == NULL) {
        std::cerr << "Error: Memory allocation failed\n";
        exit(-1); 
    }    
}

parking_lot::~parking_lot() {
    delete[] slots;
}

void parking_lot::print_parking_lot() {
    for( int i = 0; i < this->number_of_slots; i++) {
        this->slots[i].print_parking_slot();
    }
}

parking_lot* parking_lot::generate_slots(int number_of_floors, int number_of_slots) {
    parking_lot* parking_lot = new class parking_lot(number_of_floors, number_of_slots);
    if( parking_lot == NULL) {
        std::cerr << "Error: Memory allocation failed\n";
        exit(-1); 
    }    
    std::random_device rd;
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, 3); // set the range of the random number
    // 0 for van, 1 for car, 2 for motorcycle, 3 for bicycle
    for( int i = 0; i < number_of_slots; i++) {
        parking_lot->slots[i] = parking_slot(dis(gen), i / number_of_floors, i % number_of_floors);
    }

    return parking_lot;
}

