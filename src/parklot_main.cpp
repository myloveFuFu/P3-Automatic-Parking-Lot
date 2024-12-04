#include "parking_lot.h"  
#include "vehicle.h"
#include "timer.h"
#include <iostream>

int main(){
    TimeSimulator timer;
    parking_lot parklot;
    parklot.print_parking_lot();
    // std::cin.get();
    vehicle in = generate_vehicle(0);

    parklot.hint(in, timer.get_virtual_time());

        
        
        
}