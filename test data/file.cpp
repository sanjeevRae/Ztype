#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string line;
  ifstream infile;
  infile.open("example.txt");
  while (getline(infile, line)) {
    cout << line << endl;
  }
  infile.close();
  return 0;
}

