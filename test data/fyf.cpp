#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <time.h>
using namespace std;

class Spaceship {
public:
    void printShoot(string word) {
        for (int i = 0; i < word.size(); i++) {
            cout << "|";
        }
        cout << endl;
    }
};

class ZtypeGame {
private:
    vector<string> words;
    int score;
    int lives;
    int highScore;

public:
    ZtypeGame() {
        words = { "guitar", "drum", "flute", "manish", "bhuwan", "piano" };
        score = 0;
        lives = 5;
        highScore = readHighScore();
    }

    void instructions() {
        cout << "\t\t\t\t\t\t\t\t Welcome to ZTYPE!\n" << endl;
        cout << "\t\t\t\t\t\t\t\t Type the words that appear on the screen.\n" << endl;
        cout << "\t\t\t\t\t\t\t\t You have " << lives << " lives." << endl;
        cout << "\t\t\t\t\t\t\t\t Type 'shoot' to skip." << endl;
        cout << "\t\t\t\t\t\t\t\t Good luck!\n" << endl;
    }

    int readHighScore() {
        int highScore = 0;
        ifstream infile("high_score.txt");
        if (infile) {
            infile >> highScore;
            infile.close();
        }
        return highScore;
    }

    void updateHighScore() {
        if (score > highScore) {
            ofstream outfile("high_score.txt");
            if (outfile) {
                outfile << score;
                outfile.close();
                cout << "\t\t\t\t\t\t\t\t Congratulations! New high score: " << score << endl;
            }
        }
    }

    void start() {
        Spaceship spaceship;
        random_shuffle(words.begin(), words.end());
        string input;
        for (const string& word : words) {
            cout << "\t\t\t\t\t\t\t\t Incoming ship: " << endl;
            cout << "\t\\t\t\t\t\t\t Word: " << word << endl;

            auto start_time = chrono::high_resolution_clock::now();
            bool entered_input = cin >> input;
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

            if (duration > 10) {
                cout << "\t\t\t\t\t\t\t\t Time's up!" << endl;
                lives--;
            }
            else if (entered_input) {
                if (input == word) {
                    cout << "\t\t\t\t\t\t\t\t Correct!" << endl;
                    score += 10;
                }
                else if (input == "shoot") {
                    spaceship.printShoot(word);
                }
                else {
                    cout << "\t\t\t\t\t\t\t\t Incorrect, try again." << endl;
                    lives--;
                }
            }

            if (lives == 0) {
                cout << "\t\t\t\t\t\t\t\t Game Over!" << endl;
                break;
            }
            system("cls");
            cout << "\t\t\t\t\t\t\t\t Your score is: " << score << "  Lives left: " << lives << endl;
        }
        updateHighScore();
    }
};

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD.

int main() {
    // Set console window size
    SMALL_RECT windowSize = {0, 0, 100, 30};
    SetConsoleWindowInfo(console, TRUE, &windowSize);

    ZtypeGame game;

    // Display instructions
    game.instructions();

    // Start the game
    game.start();

    cout << "\n\n\t\t\t\t\t\t\t\t Thank you for playing ZTYPE!" << endl;
    return 0;
}

