#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream> // Include the file handling library

using namespace std;

class ZtypeGame {
private:
    vector<string> words;
    int score;
    int lives;

public:
    ZtypeGame() {
        words = {"guitar", "drum", "flute", "manish", "bhuwan", "piano"};
        score = 0;
        lives = 5;
    }

    // Function to save the score to a file
    void saveScore() {
        ofstream file("score.txt"); // Open a file in write mode
        if (file.is_open()) {
            file << score; // Write the score to the file
            file.close(); // Close the file
        } else {
            cout << "Failed to save score to file!" << endl;
        }
    }

    // Function to load the score from a file
    void loadScore() {
        ifstream file("score.txt"); // Open a file in read mode
        if (file.is_open()) {
            file >> score; // Read the score from the file
            file.close(); // Close the file
        } else {
            cout << "Failed to load score from file!" << endl;
        }
    }

    void start() {
        Spaceship spaceship;
        random_shuffle(words.begin(), words.end());
        string input;
        for (const string& word : words) {
            cout << "Incoming ship: " << endl;
            spaceship.printShape();
            cout << "Word: " << word << endl;

            auto start_time = chrono::high_resolution_clock::now();
            bool entered_input = cin >> input;
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

            if (duration > 10) {
                cout << "Time's up!" << endl;
                lives--;
            } else if (entered_input) {
                if (input == word) {
                    cout << "Correct!" << endl;
                    score += 10;
                } else if (input == "shoot") {
                    spaceship.printShoot(word);
                } else {
                    cout << "Incorrect, try again." << endl;
                    lives--;
                }
            }

            if (lives == 0) {
                cout << "Game Over!" << endl;
                break;
            }
            system("cls");
            cout << "Incoming ship: " << endl;
            spaceship.printShape();
            cout << "Your score is: " << score << "  Lives left: " << lives << endl;
        }

        // Save the score to file after the game is over
        saveScore();
    }

    // Function to display the previous score from file
    void displayPreviousScore() {
        loadScore();
        cout << "Previous score: " << score << endl;
    }
};

int main() {
    ZtypeGame game;
    game.displayPreviousScore(); // Display previous score before starting the game
    game.start(); // Start the game
    return 0;
}

