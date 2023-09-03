#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
    using clock_type = std::chrono::steady_clock;
    using duration_type = std::chrono::duration<double, std::milli>;

private:
    std::chrono::time_point<clock_type> start{clock_type::now()};

public:
    void reset()
    {
        start = clock_type::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<duration_type>(clock_type::now() - start).count();
    }
};

#endif