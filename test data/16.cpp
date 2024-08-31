#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream>
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
    int duration;

public:
    ZtypeGame(int gameDuration) {
        words = { "guitar", "drum", "flute", "manish", "bhuwan", "piano" };
        score = 0;
        lives = 5;
        highScore = readHighScore();
        duration = gameDuration;
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
            cout << "\t\t\t\t\t\t\t\t Word: " << word << endl;

            auto start_time = chrono::high_resolution_clock::now();
            bool entered_input = cin >> input;
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

            if (duration > this->duration) {
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
            cout << "\t\t\t\t\t\t\t\t Your score is: " << score << "  Lives left: " <<
			lives << endl;
}
}
};

int main() {
int mode;
cout << "Select game mode:" << endl;
cout << "1. Easy (30 seconds duration)" << endl;
cout << "2. Medium (20 seconds duration)" << endl;
cout << "3. Hard (10 seconds duration)" << endl;
cin >> mode;

int duration;
if (mode == 1) {
    duration = 30;
}
else if (mode == 2) {
    duration = 20;
}
else if (mode == 3) {
    duration = 10;
}
else {
    cout << "Invalid mode selected. Exiting..." << endl;
    return 0;
}

ZtypeGame game(duration);
game.instructions();
game.start();
game.updateHighScore();

return 0;
}
