#include "timer.h"

Timer::Timer(float _deltaT){
    deltaT = _deltaT;
}

void Timer::start()
{
    startTime = std::clock();
};

bool Timer::ticked()
{
    std::clock_t currentTime = std::clock();

    if ((currentTime - startTime) > ((double)CLOCKS_PER_SEC)  * deltaT)
    {
        startTime += ((double)CLOCKS_PER_SEC) * deltaT;
        return true;
    }
    return false;
}
