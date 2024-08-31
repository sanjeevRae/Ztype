#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main() {
    int timeLeft = 10;
    while (timeLeft > 0) {
        cout << "\rTimer: " << timeLeft << " seconds ";
        cout.flush();
        this_thread::sleep_for(chrono::seconds(1));
        timeLeft--;
    }
    cout << "\rTimer: 0 seconds\n";
    return 0;
}


