#include <iostream>
#include <chrono>
#include <thread>

int main() {
    int x = 0;
    while (x < 10) {
        system("cls");
        std::cout << "Text falling from top to bottom\n";
        for (int i = 0; i < x; ++i) {
            std::cout << "\n";
        }
        std::cout << "Hello, World!";
        x++;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
