#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
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
                    spaceship.printShoot(word);
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
    }
};

class ZtypeGameA {
private:
    vector<string> words;
    int score;
    int lives;

public:
    ZtypeGameA() {
        words = { "football", "tennis", "basketball", "cricket" };
        score = 0;
        lives = 5;
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
                    spaceship.printShoot(word);}
                else {
                    cout << "Incorrect, try again." << endl;
                    lives--;
                }
            }

            if(lives==0){
                cout<<"Game Over!"<<endl;
                break;
            }
            system("cls"); 
            cout<<"Incoming ship: " << endl;
          
            cout<<"Your score is: "<<score<<"  Lives left: "<<lives<<endl;
        }
    }
};


class ZtypeGameB
	 {
		private:
		vector<string> words;
		int score;
		int lives;

		public:
			ZtypeGameB()
			 {
				words = {"led", "transistor", "capacitor", "diode"};
				score = 0;
				lives = 5;
			}
			

    void start() {
        Spaceship spaceship;
        random_shuffle(words.begin(),words.end());
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
                else if(input=="shoot"){
                    spaceship.printShoot(word);
                }
                else {
                    cout << "Incorrect, try again." << endl;
                    lives--;
                }
            }

            if(lives==0){
                cout<<"Game Over!"<<endl;
                break;
            }
            system("cls"); 
            cout<<"Incoming ship: " << endl;
            
            cout<<"Your score is: "<<score<<"  Lives left: "<<lives<<endl;
        }
    }
};



int main() {
	
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
    cout << "ZTYPE" << endl;
    cout << "Welcome!" << endl;
    cout << "Press any key to continue" << endl;
    cin.get();
    int choice;
    while (true) {
        cout << "1. Instructions" << endl;
        cout << "2. Start" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                ZtypeGame().instructions();
                break;
            case 2:
            int category;
   			while (true) 
			   {
        		cout << "Choose game category" << endl;
            	cout << "1. Music" << endl;
        		cout << "2. Sport" << endl;
       			cout << "3. Electronic" << endl;
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
                cout << "Invalid choice, please try again." << endl;
        }
    }
            case 3:
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
		

