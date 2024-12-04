#include "timer.h"
#include <chrono>
#include <iostream>
#include <thread>

// Constructor, starts the timer thread
TimeSimulator::TimeSimulator(float time_scale) 
    : time_scale(time_scale), virtual_time(0.0f), running(true) {
    // Start the timer thread
    timer_thread = std::thread(&TimeSimulator::simulate_time, this);
}

// Destructor, stops the timer thread
TimeSimulator::~TimeSimulator() {
    running = false;
    if (timer_thread.joinable()) {
        timer_thread.join();  // Wait for the timer thread to finish
    }
}

// Get current virtual time
float TimeSimulator::get_virtual_time() {
    std::lock_guard<std::mutex> lock(mtx);  // Ensure thread safety
    return virtual_time;
}

// Jump the virtual time
void TimeSimulator::virtual_time_jump(float time) {
    std::lock_guard<std::mutex> lock(mtx);  // Ensure thread safety
    virtual_time += time;
}

// Set the time scale
void TimeSimulator::set_time_scale(float scale) {
    time_scale = scale;
}

// Simulate time flow
void TimeSimulator::simulate_time() {
    // Get the current time point
    std::chrono::steady_clock::time_point last_time = std::chrono::steady_clock::now();

    while (running) {
        std::chrono::steady_clock::time_point current_time = std::chrono::steady_clock::now();
        long long elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time).count();
        
        if (elapsed_time >= 1000) {  // Update virtual time every second
            // Use a mutex to protect access to virtual_time
            {
                std::lock_guard<std::mutex> lock(mtx);  
                virtual_time += time_scale;  // Increase virtual time based on the time scale
            }
            last_time = current_time;
        }
    }
}
