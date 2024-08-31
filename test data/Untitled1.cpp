#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>
using namespace std;

class Spaceship {

};

class ZtypeGame {
private:
    vector<string> words;
    int score;
    int lives;
    string player_name;

public:
    ZtypeGame() {
        words = { "guitar", "drum", "flute", "manish", "bhuwan", "piano" };
        score = 0;
        lives = 5;
    }

    void instructions() {
        cout << "Welcome to ZTYPE!\n" << endl;
        cout << "Type the words that appear on the screen to destroy incoming alien ships.\n" << endl;
        cout << "You have " << lives << " lives." << endl;
        cout << "Type 'shoot' to shoot the incoming word." << endl;
        cout << "Good luck!\n" << endl;
    }

    void readScoreFromFile() {
        ifstream file("scores.txt");
        if (file.is_open()) {
            file >> player_name >> score;
            file.close();
        }
    }

    void start() {
        Spaceship spaceship;
        random_shuffle(words.begin(), words.end());
        string input;
        for (const string& word : words) {
            cout << "Incoming ship: " << endl;
            cout << "Word: " << word << endl;

            auto start_time = chrono::high_resolution_clock::now();
            bool entered_input = cin >> input;
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

            if (duration > 10) {
                cout << "Time's up!" << endl;
                lives--;
            }
            else if (entered_input) {
                if (input == word) {
                    cout << "Correct!" << endl;
                    score += 10;
                }
                else if (input == "shoot") {
                   
                }
                else {
                    cout << "Incorrect, try again." << endl;
                    lives--;
                }
            }

            if (lives == 0) {
                cout << "Game Over!" << endl;
                break;
            }
            system("cls");
            cout << "Your score is: " << score << "  Lives left: " << lives << endl;
        }

        ofstream file("scores.txt");
        if (file.is_open()) {
            file << player_name << " " << score << endl;
            file.close();
        }
    }
};

int main() {
    ZtypeGame game;
    game.instructions();
    game.readScoreFromFile();
    game.start();
    return 0;
}

