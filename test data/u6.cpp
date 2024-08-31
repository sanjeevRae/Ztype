#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <vector>

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

class ZtypeGameA {
private:
    vector<string> words;
    int score;
    int lives;
    int highScore;

public:
    ZtypeGameA() {
        words = { "guitar", "drum", "flute", "manish", "bhuwan", "piano" };
        score = 0;
        lives = 5;
        highScore = readHighScore();
    }

    void instructions() {
        cout << "\t\t\t\t\t\t\t\t Welcome to ZTYPE!\n" << endl;
        cout << "\t\t\t\t\t\t\t\t Type the words that appear on the screen.\n" << endl;
        cout << "\t\t\t\t\t\t\t\t You have " << lives << " lives." << endl;
        cout << "\t\t\t\t\t\t\t\t Type 'shoot'to shoot to skip." << endl;
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
            cout << "\t\\t\t\t\t\t\t Your score is: " << score << "  Lives left: " << lives << endl;
        }
        updateHighScore();
    }
};


class ZtypeGameB {
private:
    vector<string> words;
    int score;
    int lives;
    int highScore;

public:
    ZtypeGameB() {
        words = { "guitar", "drum", "flute", "manish", "bhuwan", "piano" };
        score = 0;
        lives = 5;
        highScore = readHighScore();
    }

    void instructions() {
        cout << "\t\t\t\t\t\t\t\t Welcome to ZTYPE!\n" << endl;
        cout << "\t\t\t\t\t\t\t\t Type the words that appear on the screen.\n" << endl;
        cout << "\t\t\t\t\t\t\t\t You have " << lives << " lives." << endl;
        cout << "\t\t\t\t\t\t\t\t Type 'shoot' to shoot to skip." << endl;
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



int main() {
	
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t************" << endl;
    cout << "\t\t\t\t\t\t\t\t***ZTYPE***" << endl;
    cout << "\t\t\t\t\t\t\t************" << endl;
    cout << "\t\t\t\t\t\t\t\t Welcome!" << endl;
    cout << "\t\t\t\t\t\t\t\t Press enter to continue" << endl;
    cin.get();
    int choice;
    while (true) {
        cout << "\t\t\t\t\t\t\t\t 1. Instructions" << endl;
        cout << "\t\t\t\t\t\t\t\t 2. Start" << endl;
        cout << "\t\t\t\t\t\t\t\t 3. Exit" << endl;
        cin >> choice;
        switch (choice) {
             case 1:
                ZtypeGame().instructions();
                break;
            case 2:
            int category;
   			while (true) 
			   {
        		cout << "\t\t\t\t\t\t\t\t Choose game category" << endl;
            	cout << "\t\t\t\t\t\t\t\t 1. Music" << endl;
        		cout << "\t\t\t\t\t\t\t\t 2. Sport" << endl;
       			cout << "\t\t\t\t\t\t\t\t 3. Electronic" << endl;
        cin >> category;
        switch (category) 
		{
            case 1:
                ZtypeGame().start(); break;
                break;
            case 2:
                ZtypeGameA().start(); break;
            case 3:
               ZtypeGameB().start(); break;
            default:
           
                cout << "\t\t\t\t\t\t\t\t Invalid choice, please try again." << endl;
        }
    }
            case 3:
                return 0;
            default:
                cout << "\t\t\t\t\t\t\t\t Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
		

