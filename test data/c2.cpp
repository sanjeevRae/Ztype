#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    int countdown;
    cout << "Enter countdown time in seconds: ";
    cin >> countdown;

    for (int i = countdown; i >= 0; i--)
    {
        cout << "Time left: " << i << " seconds" << endl;
        sleep(1);
    }

    cout << "Time's up!" << endl;
    return 0;
}

