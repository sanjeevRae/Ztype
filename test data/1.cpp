#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

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
            cout << "Welcome to Ztype!\n" << endl;
            cout << "Type the words that appear on the screen to destroy incoming alien ships.\n" << endl;
            cout << "You have " << lives << " lives and 30 seconds to type each word.\n" << endl;
            cout << "Good luck!\n" << endl;

            //random engine to shuffle the words


            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            shuffle(words.begin(), words.end(), default_random_engine(seed));
            string input;
            
            for (const string& word : words) {
                cout << "Type the word: " << word << endl;
                auto start = chrono::high_resolution_clock::now();
                cin >> input;
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed = end - start;
                if (elapsed.count()>30) {
                    cout<<"Time Out!"<<endl;
                    lives--;
                }
                else if (input == word) {
                    cout << "Correct!" << endl;
                    score++;
                } else {
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