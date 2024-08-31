#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    int seconds = 30;

    while (seconds >= 0)
    {
        std::cout << seconds << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds--;
    }

    std::cout << "Time's up!" << std::endl;

    return 0;
}

