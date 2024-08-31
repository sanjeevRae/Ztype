#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    int seconds = 30;

    cout << "Starting countdown timer...\n" << endl;

    for(int i=seconds; i>=0; i--)
    {
        cout << "Seconds remaining: " << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "\nTime's up!" << endl;

    return 0;
}

