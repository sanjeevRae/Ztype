#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    for (int i = 10; i >= 0; i--) {
        cout << "Time left: " << i << " ";
        cout.flush();
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\r";
    }

    cout << endl; 

    return 0;
}

