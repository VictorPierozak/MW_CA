#pragma once
#include<chrono>

class Timer
{
public:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = Clock::time_point;
    using Duration = std::chrono::duration<double, std::milli>;

    static void start()
    {
        start_time_ = Clock::now();
    }

    static void stop()
    {
        duration_ = std::chrono::duration<double, std::milli>(Clock::now() - start_time_);
    }

    static double getMilliseconds()
    {
        return duration_.count();
    }

private:
    static TimePoint start_time_;
    static Duration duration_;
};