#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string name;
    
    cout << "Please enter your name: ";
    getline(cin, name);
    
    
    ofstream outfile("details.txt");
    if (!outfile.is_open()) {
        cout << "Error: Could not open file for writing." << endl;
        return 1;
    }
 
    outfile << "Name: " << name << endl;
    outfile.close();
    ifstream infile("details.txt");
    if (!infile.is_open()) {
        cout << "Error: Could not open file for reading." << endl;
        return 1;
    }
    
   
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }
    
    infile.close();
    
    return 0;
}

