#pragma once

#include <chrono>

class Timer //via https://codereview.stackexchange.com/questions/196245/extremely-simple-timer-class-in-c/196253
{
private:
    std::chrono::time_point<std::chrono::steady_clock> m_StartTime;

public:
    void Start();
    float GetDuration();
};
