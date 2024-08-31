#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    int x = 0;
    while (x < 10) {
        system("cls");  
        cout << "Text falling from top to bottom\n";
        for (int i = 0; i < x; ++i) {
            cout << "\n";
        }
        cout << "Hello, World!";
        x++;
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    return 0;
}

