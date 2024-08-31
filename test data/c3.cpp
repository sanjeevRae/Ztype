#include <iostream>
#include <unistd.h> // for sleep() function

int main() {
  int count = 30;

  while (count > 0) {
    std::cout << count << " seconds remaining..." << std::endl;
    sleep(1); // pause for 1 second
    count--;
  }

  std::cout << "Time's up!" << std::endl;

  return 0;
}

