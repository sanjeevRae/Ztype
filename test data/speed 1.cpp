#include <chrono>
#include <iostream>
#include <string>

int main() {
  std::string target = "This is the target text.";
  std::string typed_text;
  std::cout << "Type the following text:\n" << target << std::endl;
  
  auto start = std::chrono::steady_clock::now();
  
  while (typed_text != target) {
    std::getline(std::cin, typed_text);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    int typed_characters = typed_text.length();
    float typing_speed = typed_characters / elapsed_time;
    std::cout << "Your typing speed is " << typing_speed << " characters per second." << std::endl;
  }
  
  std::cout << "You've completed the game!" << std::endl;
  
  return 0;
}

