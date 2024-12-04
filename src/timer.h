#ifndef TIMESIMULATOR_H
#define TIMESIMULATOR_H

#include <thread>
#include <mutex>

class TimeSimulator {
public:
    // Constructor: accepts time scale
    TimeSimulator(float time_scale = 1.0f);

    // Destructor: stops the timer thread
    ~TimeSimulator();

    // Get current virtual time
    float get_virtual_time();

    void virtual_time_jump(float time = 1.0f);

    // Set the time scale
    void set_time_scale(float scale);

private:
    // Function to simulate time flow
    void simulate_time();

    float time_scale;             // Time scale factor
    float virtual_time;           // Virtual time
    std::mutex mtx;               // Mutex to protect virtual time
    bool running;                 // Control if the timer thread is running
    std::thread timer_thread;     // Timer thread
};

#endif // TIMESIMULATOR_H

