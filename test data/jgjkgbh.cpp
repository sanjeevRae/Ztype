#include <iostream>

int main() {
    int choice;

    std::cout << "Enter your choice (1 for 'Hello', 2 for 'Bye', 3 to exit): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Hello!" << std::endl;
            break;
        case 2:
            std::cout << "Bye!" << std::endl;
            break;
        case 3:
            std::cout << "Exiting..." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }

    return 0;
}

