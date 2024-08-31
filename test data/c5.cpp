#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::cout << "Starting 30 second timer...\n";
    std::chrono::seconds countdown_time(30);
    while (countdown_time.count() > 0) {
        std::cout << "Time remaining: " << countdown_time.count() << " seconds\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        countdown_time -= std::chrono::seconds(1);
    }
    std::cout << "Time's up!\n";
    return 0;
}

