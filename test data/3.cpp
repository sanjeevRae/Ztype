#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

class Ship {
    public:
        void printShape() {
            for (int i = 1; i <= 5; i++) {
                for (int j = 1; j <= i; j++) {
                    cout << "* ";
                }
                cout << endl;
            }
        }
};

class ZtypeGame {
    private:
        vector<string> words;
        int score;
        int lives;
    public:
        ZtypeGame() {
            words = {"example", "another", "word", "list"};
            score = 0;
            lives = 5;
        }

        void start() {
            Ship ship;
            cout << "Welcome to Ztype!\n" << endl;
            cout << "Type the words that appear on the screen to destroy incoming alien ships.\n" << endl;
            cout << "You have " << lives << " lives." << endl;
            cout << "Good luck!\n" << endl;

            //random engine to shuffle the words
            random_shuffle(words.begin(),words.end());
            string input;
            for (const string& word : words) {
                cout << "Incoming ship: " << endl;
                ship.printShape();
                cout << endl;
                cout << "Type the word: " << word << endl;

                auto start = chrono::high_resolution_clock::now();
                cin >> input;
                auto end = chrono::high_resolution_clock::now();
                auto elapsed = chrono::duration_cast<chrono::seconds>(end - start).count();

                if (elapsed > 10) {
                    cout << "Time's up! You missed this one." << endl;
                    lives--;
                }
                else if (input == word) {
                    cout << "Correct!" << endl;
                    score++;
                }
                else if(input=="shoot"){
                    cout<<"You shooted the ship!"<<endl;
                }
                else {
                    cout << "Incorrect, try again." << endl;
                    lives--;
                }
                if(lives==0){
                    cout<<"Game Over!"<<endl;
                    break;
                }
            }
            cout<<"Your score is: "<<score<<endl;
            cout<<"Lives left: "<<lives<<endl;
        }
};

int main() {
    ZtypeGame game;
    game.start();
    return 0;
}

