#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <windows.h>
#include <chrono>
#include <fstream>
using namespace std;

class ZtypeGame_Easy {
private:
    vector<string> words;
    int score;
    int lives;
    int highScore;

public:
    ZtypeGame_Easy() {
    words = { "piano",
"guitar",
"violin",
"cello",
"flute",
"trumpet",
"saxophone",
"clarinet",
"drums",
"tambourine",
"harp",
"accordion",
"ukulele",
"banjo",
"harmonica",
"xylophone",
"trombone",
"french horn",
"bagpipes",
"sitar",
"tabla",
"djembe",
"didgeridoo",
"marimba",
"synthesizer",
"keyboard",
"mandolin",
"oboe",
"bassoon",
"vibraphone" };

    string playerName;
    highScore = readHighScore(playerName);
    cout << "\t\t\t\t\t\t\t\t Welcome, " << playerName << "! Your current high score: " << highScore << endl;
    score = 0;
    lives = 5;
}

    void instructions() {
    system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
        cout << "\t\t\t\t\t\t\t\t Welcome to ZTYPE!\n" << endl;
        cout << "\t\t\t\t\t\t\t\t Type the words that appear on the screen.\n" << endl;
        cout << "\t\t\t\t\t\t\t\t You have " << lives << " lives." << endl;
        cout << "\t\t\t\t\t\t\t\t Good luck!\n" << endl;
    }

    int readHighScore(string& playerName) {
    int highScore = 0;
    ifstream infile("high_score.txt");
    if (infile) {
        infile >> playerName >> highScore;
        infile.close();
    }
    return highScore;
}


    void saveScoreToFile(const string& playerName) {
    ofstream outfile("high_score.txt");
    if (outfile) {
        outfile << playerName << " " << score;
        outfile.close();
        cout << "\t\t\t\t\t\t\t\t Congratulations, " << playerName << "! New high score: " << score << endl;
    }
}



   void updateHighScore() {
    if (score > highScore) {
        string playerName;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t\t\t You achieved a new high score!" << endl;
        cout << "\t\t\t\t\t\t\t\t Please enter your name: ";
        cin >> playerName;
        saveScoreToFile(playerName);
    }
}



    void start() {
        
        random_shuffle(words.begin(), words.end());
        string input;
        for (const string& word : words) {
            cout << "\t\t\t\t\t\t\t\t Incoming Word: " << endl;
            cout << "\t\t\t\t\t\t\t\t Word: " << word << endl;

            auto start_time = chrono::high_resolution_clock::now();
            bool entered_input = cin >> input;
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

            if (duration > 30) {
                cout << "\t\t\t\t\t\t\t\t Time's up!" << endl;
                lives--;
            }
            else if (entered_input) {
                if (input == word) {
                    cout << "\t\t\t\t\t\t\t\t Correct!" << endl;
                    Beep(1000, 500);
                    score += 10;
                }
                else {
                	cout << "\a" << endl;
                    cout << "\t\t\t\t\t\t\t\t Incorrect, try again." << endl;
                    lives--;
                }
            }

            if (lives == 0) 
			{cout << endl;
	cout << endl;
	cout << endl;
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                cout << "\t\t\t\t\t\t\t\t Game Over!" << endl;
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                break;
            }
            system("cls");
            cout << "\t\t\t\t\t\t\t\t Your score is: " << score << "  Lives left: " << lives << endl;
        }
        updateHighScore();
    }
};



class ZtypeGame_Medium {
private:
    vector<string> words;
    int score;
    int lives;
    int highScore;

public:
    ZtypeGame_Medium() {
    words = { "piano",
"guitar",
"violin",
"cello",
"flute",
"trumpet",
"saxophone",
"clarinet",
"drums",
"tambourine",
"harp",
"accordion",
"ukulele",
"banjo",
"harmonica",
"xylophone",
"trombone",
"french horn",
"bagpipes",
"sitar",
"tabla",
"djembe",
"didgeridoo",
"marimba",
"synthesizer",
"keyboard",
"mandolin",
"oboe",
"bassoon",
"vibraphone" };
    
    
    string playerName;
    highScore = readHighScore(playerName);
    cout << "\t\t\t\t\t\t\t\t Welcome, " << playerName << "! Your current high score: " << highScore << endl;
    score = 0;
    lives = 5;
}

   
    void instructions() {
    system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
        cout << "\t\t\t\t\t\t\t\t Welcome to ZTYPE!\n" << endl;
        cout << "\t\t\t\t\t\t\t\t Type the words that appear on the screen.\n" << endl;
        cout << "\t\t\t\t\t\t\t\t You have " << lives << " lives." << endl;

        cout << "\t\t\t\t\t\t\t\t Good luck!\n" << endl;
    }


    int readHighScore(string& playerName) {
    int highScore = 0;
    ifstream infile("high_score.txt");
    if (infile) {
        infile >> playerName >> highScore;
        infile.close();
    }
    return highScore;
}

    void saveScoreToFile(const string& playerName) {
    ofstream outfile("high_score.txt");
    if (outfile) {
        outfile << playerName << " " << score;
        outfile.close();
        cout << "\t\t\t\t\t\t\t\t Congratulations, " << playerName << "! New high score: " << score << endl;
    }
}



   void updateHighScore() {
    if (score > highScore) {
        string playerName;
        cout << "\t\t\t\t\t\t\t\t You achieved a new high score!" << endl;
        cout << "\t\t\t\t\t\t\t\t Please enter your name: ";
        cin >> playerName;
        saveScoreToFile(playerName);
    }
}


    void start() {
        
        random_shuffle(words.begin(), words.end());
        string input;
        for (const string& word : words) {
            cout << "\t\t\t\t\t\t\t\t Incoming word: " << endl;
            cout << "\t\t\t\t\t\t\t\t Word: " << word << endl;

            auto start_time = chrono::high_resolution_clock::now();
            bool entered_input = cin >> input;
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

            if (duration > 20) {
                 cout << "\t\t\t\t\t\t\t\t Time's up!" << endl;
                lives--;
            }
            else if (entered_input) {
                if (input == word) {
                    cout << "\t\t\t\t\t\t\t\t Correct!" << endl;
                    Beep(1000, 500);
                    score += 10;
                }
                else {
                	cout << "\a" << endl;
                    cout << "\t\t\t\t\t\t\t\t Incorrect, try again." << endl;
                    lives--;
                }
            }

            if (lives == 0) 
            
			{
			
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                cout << "\t\t\t\t\t\t\t\t Game Over!" << endl;
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
            }
            system("cls");
            cout << "\t\t\t\t\t\t\t\t Your score is: " << score << "  Lives left: " << lives << endl;
        }
        updateHighScore();
    }
};

class ZtypeGame_Hard {
private:
    vector<string> words;
    int score;
    int lives;
    int highScore;

public:
    ZtypeGame_Hard() {
words = { "piano",
"guitar",
"violin",
"cello",
"flute",
"trumpet",
"saxophone",
"clarinet",
"drums",
"tambourine",
"harp",
"accordion",
"ukulele",
"banjo",
"harmonica",
"xylophone",
"trombone",
"french horn",
"bagpipes",
"sitar",
"tabla",
"djembe",
"didgeridoo",
"marimba",
"synthesizer",
"keyboard",
"mandolin",
"oboe",
"bassoon",
"vibraphone" };

    
    
    string playerName;
    highScore = readHighScore(playerName);
    cout << "Welcome, " << playerName << "! Your current high score: " << highScore << endl;
    score = 0;
    lives = 5;
}

    void instructions() {
    	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
        cout << "\t\t\t\t\t\t\t\t Welcome to ZTYPE!\n" << endl;
        cout << "\t\t\t\t\t\t\t\t Type the words that appear on the screen.\n" << endl;
        cout << "\t\t\t\t\t\t\t\t You have " << lives << " lives." << endl;
        cout << "\t\t\t\t\t\t\t\t Good luck!\n" << endl;
    }

   int readHighScore(string& playerName) {
    int highScore = 0;
    ifstream infile("high_score.txt");
    if (infile) {
        infile >> playerName >> highScore;
        infile.close();
    }
    return highScore;
}


    void saveScoreToFile(const string& playerName) {
    ofstream outfile("high_score.txt");
    if (outfile) {
        outfile << playerName << " " << score;
        outfile.close();
        cout << "\t\t\t\t\t\t\t\t Congratulations, " << playerName << "! New high score: " << score << endl;
    }
}



   void updateHighScore() {
    if (score > highScore) {
        string playerName;
        cout << "\t\t\t\t\t\t\t\t You achieved a new high score!" << endl;
        cout << "\t\t\t\t\t\t\t\t Please enter your name: ";
        cin >> playerName;
        saveScoreToFile(playerName);
    }
}


    void start() {
        
        random_shuffle(words.begin(), words.end());
        string input;
        for (const string& word : words) {
            cout << "\t\t\t\t\t\t\t\t Incoming word: " << endl;
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
                    Beep(1000, 500);
                    score += 10;
                }
                else {
                	cout << "\a" << endl;
                    cout << "\t\t\t\t\t\t\t\t Incorrect, try again." << endl;
                    lives--;
                }
            }

            if (lives == 0) 
			{cout << endl;
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
            	
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                cout << "\t\t\t\t\t\t\t\t Game Over!" << endl;
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                break;
            }
            system("cls");
            cout << "\t\t\t\t\t\t\t\t Your score is: " << score << "  Lives left: " << lives << endl;
        }
        updateHighScore();
    }
};




class ZtypeGameA_Easy {
private:
    vector<string> words;
    int score;
    int lives;
    int highScore;

public:
    ZtypeGameA_Easy() {
    words = { "football", "chess", "basketball", "cricket", "tennis", "badminton", "baseball", "rugby", "golf",
	 "athletics ", "swimming", "boxing", "martial arts", "wrestling",
	  "gymnastics", "volleyball", "table tennis", "hockey ", "cycling", "sailing", "surfing"
	  , "skiing", "snowboarding", "archery", "fencing", "equestrian", "formula 1 racing",
	   "weightlifting", "canoeing", "kayaking", "squash", "shooting" };
    
    
    string playerName;
    highScore = readHighScore(playerName);
    cout << "\t\t\t\t\t\t\t\t Welcome, " << playerName << "! Your current high score: " << highScore << endl;
    score = 0;
    lives = 5;
}

    void instructions() {
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
        cout << "\t\t\t\t\t\t\t\t Welcome to ZTYPE!\n" << endl;
        cout << "\t\t\t\t\t\t\t\t Type the words that appear on the screen.\n" << endl;
        cout << "\t\t\t\t\t\t\t\t You have " << lives << " lives." << endl;
        cout << "\t\t\t\t\t\t\t\t Good luck!\n" << endl;
    }

    int readHighScore(string& playerName) {
    int highScore = 0;
    ifstream infile("high_score.txt");
    if (infile) {
        infile >> playerName >> highScore;
        infile.close();
    }
    return highScore;
}


    void saveScoreToFile(const string& playerName) {
    ofstream outfile("high_score.txt");
    if (outfile) {
        outfile << playerName << " " << score;
        outfile.close();
        cout << "\t\t\t\t\t\t\t\t Congratulations, " << playerName << "! New high score: " << score << endl;
    }
}



   void updateHighScore() {
    if (score > highScore) {
        string playerName;
        cout << "\t\t\t\t\t\t\t\t You achieved a new high score!" << endl;
        cout << "\t\t\t\t\t\t\t\t Please enter your name: ";
        cin >> playerName;
        saveScoreToFile(playerName);
    } 
}


    void start() {
       
        random_shuffle(words.begin(), words.end());
        string input;
        for (const string& word : words) {
            cout << "\t\t\t\t\t\t\t\t Incoming word : " << endl;
            cout << "\t\t\t\t\t\t\t\t Word: " << word << endl;

            auto start_time = chrono::high_resolution_clock::now();
            bool entered_input = cin >> input;
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

            if (duration > 30) {
                                cout << "\t\t\t\t\t\t\t\t Time's up!" << endl;
                lives--;
            }
            else if (entered_input) {
                if (input == word) {
                    cout << "\t\t\t\t\t\t\t\t Correct!" << endl;
                    Beep(1000, 500);
                    score += 10;
                }
                else {
                	cout << "\a" << endl;
                    cout << "\t\t\t\t\t\t\t\t Incorrect, try again." << endl;
                    lives--;
                }
            }

            if (lives == 0) 
			{cout << endl;
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
            	
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                cout << "\t\t\t\t\t\t\t\t Game Over!" << endl;
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                break;
            }
            system("cls");
            cout << "\t\t\t\t\t\t\t\t Your score is: " << score << "  Lives left: " << lives << endl;
        }
        updateHighScore();
    }
};


class ZtypeGameA_Medium {
private:
    vector<string> words;
    int score;
    int lives;
    int highScore;

public:
    ZtypeGameA_Medium() {
    words = { "football", "chess", "basketball", "cricket", "tennis", "badminton", "baseball", "rugby", "golf",
	 "athletics ", "swimming", "boxing", "martial arts", "wrestling",
	  "gymnastics", "volleyball", "table tennis", "hockey ", "cycling", "sailing", "surfing"
	  , "skiing", "snowboarding", "archery", "fencing", "equestrian", "formula 1 racing",
	   "weightlifting", "canoeing", "kayaking", "squash", "shooting" };
    
    
    string playerName;
    highScore = readHighScore(playerName);
    cout << "Welcome, " << playerName << "! Your current high score: " << highScore << endl;
    score = 0;
    lives = 5;
}

    void instructions() {
    	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
        cout << "\t\t\t\t\t\t\t\t Welcome to ZTYPE!\n" << endl;
        cout << "\t\t\t\t\t\t\t\t Type the words that appear on the screen.\n" << endl;
        cout << "\t\t\t\t\t\t\t\t You have " << lives << " lives." << endl;

        cout << "\t\t\t\t\t\t\t\t Good luck!\n" << endl;
    }

    int readHighScore(string& playerName) {
    int highScore = 0;
    ifstream infile("high_score.txt");
    if (infile) {
        infile >> playerName >> highScore;
        infile.close();
    }
    return highScore;
}

    void saveScoreToFile(const string& playerName) {
    ofstream outfile("high_score.txt");
    if (outfile) {
        outfile << playerName << " " << score;
        outfile.close();
        cout << "\t\t\t\t\t\t\t\t Congratulations, " << playerName << "! New high score: " << score << endl;
    }
}



   void updateHighScore() {
    if (score > highScore) {
        string playerName;
        cout << "\t\t\t\t\t\t\t\t You achieved a new high score!" << endl;
        cout << "\t\t\t\t\t\t\t\t Please enter your name: ";
        cin >> playerName;
        saveScoreToFile(playerName);
    }
}


    void start() {
        
        random_shuffle(words.begin(), words.end());
        string input;
        for (const string& word : words) {
            cout << "\t\t\t\t\t\t\t\t Incoming word: " << endl;
            cout << "\t\t\t\t\t\t\t\t Word: " << word << endl;

            auto start_time = chrono::high_resolution_clock::now();
            bool entered_input = cin >> input;
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

            if (duration > 20) {
                cout << "\t\t\t\t\t\t\t\t Time's up!" << endl;
                lives--;
            }
            else if (entered_input) {
                if (input == word) {
                    cout << "\t\t\t\t\t\t\t\t Correct!" << endl;
                    Beep(1000, 500);
                    score += 10;
                }
                else {
                	cout << "\a" << endl;
                    cout << "\t\t\t\t\t\t\t\t Incorrect, try again." << endl;
                    lives--;
                }
            }

            if (lives == 0) 
			{cout << endl;
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
            	
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                cout << "\t\t\t\t\t\t\t\t Game Over!" << endl;
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                break;
            }
            system("cls");
            cout << "\t\t\t\t\t\t\t\t Your score is: " << score << "  Lives left: " << lives << endl;
        }
        updateHighScore();
    }
};


class ZtypeGameA_Hard {
private:
    vector<string> words;
    int score;
    int lives;
    int highScore;

public:
    ZtypeGameA_Hard() {
    words = { "football", "chess", "basketball", "cricket", "tennis", "badminton", "baseball", "rugby", "golf",
	 "athletics ", "swimming", "boxing", "martial arts", "wrestling",
	  "gymnastics", "volleyball", "table tennis", "hockey ", "cycling", "sailing", "surfing"
	  , "skiing", "snowboarding", "archery", "fencing", "equestrian", "formula 1 racing",
	   "weightlifting", "canoeing", "kayaking", "squash", "shooting" };
    
    
    string playerName;
    highScore = readHighScore(playerName);
    cout << "Welcome, " << playerName << "! Your current high score: " << highScore << endl;
    score = 0;
    lives = 5;
}

    void instructions() {
    	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
        cout << "\t\t\t\t\t\t\t\t Welcome to ZTYPE!\n" << endl;
        cout << "\t\t\t\t\t\t\t\t Type the words that appear on the screen.\n" << endl;
        cout << "\t\t\t\t\t\t\t\t You have " << lives << " lives." << endl;

        cout << "\t\t\t\t\t\t\t\t Good luck!\n" << endl;
    }

    int readHighScore(string& playerName) {
    int highScore = 0;
    ifstream infile("high_score.txt");
    if (infile) {
        infile >> playerName >> highScore;
        infile.close();
    }
    return highScore;
}

    void saveScoreToFile(const string& playerName) {
    ofstream outfile("high_score.txt");
    if (outfile) {
        outfile << playerName << " " << score;
        outfile.close();
        cout << "\t\t\t\t\t\t\t\t Congratulations, " << playerName << "! New high score: " << score << endl;
    }
}



   void updateHighScore() {
    if (score > highScore) {
        string playerName;
        cout << "\t\t\t\t\t\t\t\t You achieved a new high score!" << endl;
        cout << "\t\t\t\t\t\t\t\t Please enter your name: ";
        cin >> playerName;
        saveScoreToFile(playerName);
    }
}


    void start() {
       
        random_shuffle(words.begin(), words.end());
        string input;
        for (const string& word : words) {
            cout << "\t\t\t\t\t\t\t\t Incoming word: " << endl;
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
                    Beep(1000, 500);
                    score += 10;
                }
                else {
                	cout << "\a" << endl;
                    cout << "\t\t\t\t\t\t\t\t Incorrect, try again." << endl;
                    lives--;
                }
            }

            if (lives == 0) 
			{cout << endl;
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
            	
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                cout << "\t\t\t\t\t\t\t\t Game Over!" << endl;
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                break;
            }
            system("cls");
            cout << "\t\t\t\t\t\t\t\t Your score is: " << score << "  Lives left: " << lives << endl;
        }
        updateHighScore();
    }
};


class ZtypeGameB_Easy {
private:
    vector<string> words;
    int score;
    int lives;
    int highScore;

public:
    ZtypeGameB_Easy() {
    words = { "television", "computer", "laptop", "smartphone", "tablet", "digital camera", "headphones", "speakers",
	 "DVD", "home theater system", "game console", "MP3 player",
	  "smartwatch", "fitness tracker", "projector", "printer", "scanner", "router", "modem", "external hard drive", 
	  "USB flash drive", "wireless earbuds", "VR headset", "drone", "GPS navigation system",
	   "home security system", "smart home devices", "e-book reader",
	    "power bank", "robot", "vacuum cleaner" };
    
    
    string playerName;
    highScore = readHighScore(playerName);
    cout << "Welcome, " << playerName << "! Your current high score: " << highScore << endl;
    score = 0;
    lives = 5;
}
    void instructions() {
    	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
        cout << "\t\t\t\t\t\t\t\t Welcome to ZTYPE!\n" << endl;
        cout << "\t\t\t\t\t\t\t\t Type the words that appear on the screen.\n" << endl;
        cout << "\t\t\t\t\t\t\t\t You have " << lives << " lives." << endl;
     
        cout << "\t\t\t\t\t\t\t\t Good luck!\n" << endl;
    }

 int readHighScore(string& playerName) {
    int highScore = 0;
    ifstream infile("high_score.txt");
    if (infile) {
        infile >> playerName >> highScore;
        infile.close();
    }
    return highScore;
}

    void saveScoreToFile(const string& playerName) {
    ofstream outfile("high_score.txt");
    if (outfile) {
        outfile << playerName << " " << score;
        outfile.close();
        cout << "\t\t\t\t\t\t\t\t Congratulations, " << playerName << "! New high score: " << score << endl;
    }
}



   void updateHighScore() {
    if (score > highScore) {
        string playerName;
        cout << "\t\t\t\t\t\t\t\t You achieved a new high score!" << endl;
        cout << "\t\t\t\t\t\t\t\t Please enter your name: ";
        cin >> playerName;
        saveScoreToFile(playerName);
    }
}


    void start() {
      
        random_shuffle(words.begin(), words.end());
        string input;
        for (const string& word : words) {
            cout << "\t\t\t\t\t\t\t\t Incoming word: " << endl;
            cout << "\t\t\t\t\t\t\t\t Word: " << word << endl;

            auto start_time = chrono::high_resolution_clock::now();
            bool entered_input = cin >> input;
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

            if (duration > 30) {
                                cout << "\t\t\t\t\t\t\t\t Time's up!" << endl;
                lives--;
            }
            else if (entered_input) {
                if (input == word) {
                    cout << "\t\t\t\t\t\t\t\t Correct!" << endl;
                    Beep(1000, 500);
                    score += 10;
                }
                else {
                	cout << "\a" << endl;
                    cout << "\t\t\t\t\t\t\t\t Incorrect, try again." << endl;
                    lives--;
                }
            }

            if (lives == 0) 
			{cout << endl;
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
            	
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                cout << "\t\t\t\t\t\t\t\t Game Over!" << endl;
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                break;
            }
            system("cls");
            cout << "\t\t\t\t\t\t\t\t Your score is: " << score << "  Lives left: " << lives << endl;
        }
        updateHighScore();
    }
};


class ZtypeGameB_Medium {
private:
    vector<string> words;
    int score;
    int lives;
    int highScore;

public:
    ZtypeGameB_Medium() {
   words = { "television", "computer", "laptop", "smartphone", "tablet", "digital camera", "headphones", "speakers",
	 "DVD", "home theater system", "game console", "MP3 player",
	  "smartwatch", "fitness tracker", "projector", "printer", "scanner", "router", "modem", "external hard drive", 
	  "USB flash drive", "wireless earbuds", "VR headset", "drone", "GPS navigation system",
	   "home security system", "smart home devices", "e-book reader",
	    "power bank", "robot", "vacuum cleaner" };
    
    
    
    string playerName;
    highScore = readHighScore(playerName);
    cout << "Welcome, " << playerName << "! Your current high score: " << highScore << endl;
    score = 0;
    lives = 5;
}

    void instructions() {
    	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
        cout << "\t\t\t\t\t\t\t\t Welcome to ZTYPE!\n" << endl;
        cout << "\t\t\t\t\t\t\t\t Type the words that appear on the screen.\n" << endl;
        cout << "\t\t\t\t\t\t\t\t You have " << lives << " lives." << endl;
    
        cout << "\t\t\t\t\t\t\t\t Good luck!\n" << endl;
    }

int readHighScore(string& playerName) {
    int highScore = 0;
    ifstream infile("high_score.txt");
    if (infile) {
        infile >> playerName >> highScore;
        infile.close();
    }
    return highScore;
}


    void saveScoreToFile(const string& playerName) {
    ofstream outfile("high_score.txt");
    if (outfile) {
        outfile << playerName << " " << score;
        outfile.close();
        cout << "\t\t\t\t\t\t\t\t Congratulations, " << playerName << "! New high score: " << score << endl;
    }
}



   void updateHighScore() {
    if (score > highScore) {
        string playerName;
        cout << "\t\t\t\t\t\t\t\t You achieved a new high score!" << endl;
        cout << "\t\t\t\t\t\t\t\t Please enter your name: ";
        cin >> playerName;
        saveScoreToFile(playerName);
    }
}


    void start() {
        
        random_shuffle(words.begin(), words.end());
        string input;
        for (const string& word : words) {
            cout << "\t\t\t\t\t\t\t\t Incoming word: " << endl;
            cout << "\t\t\t\t\t\t\t\t Word: " << word << endl;

            auto start_time = chrono::high_resolution_clock::now();
            bool entered_input = cin >> input;
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

            if (duration > 20) {
                                cout << "\t\t\t\t\t\t\t\t Time's up!" << endl;
                lives--;
            }
            else if (entered_input) {
                if (input == word) {
                    cout << "\t\t\t\t\t\t\t\t Correct!" << endl;
                    Beep(1000, 500);
                    score += 10;
                }
                else {
                	cout << "\a" << endl;
                    cout << "\t\t\t\t\t\t\t\t Incorrect, try again." << endl;
                    lives--;
                }
            }

            if (lives == 0) 
			{
				
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
            	
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                cout << "\t\t\t\t\t\t\t\t Game Over!" << endl;
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                break;
            }
            system("cls");
            cout << "\t\t\t\t\t\t\t\t Your score is: " << score << "  Lives left: " << lives << endl;
        }
        updateHighScore();
    }
};


class ZtypeGameB_Hard {
private:
    vector<string> words;
    int score;
    int lives;
    int highScore;

public:
    ZtypeGameB_Hard() {
  words = { "television", "computer", "laptop", "smartphone", "tablet", "digital camera", "headphones", "speakers",
	 "DVD", "home theater system", "game console", "mp3 player",
	  "smartwatch", "fitness tracker", "projector", "printer", "scanner", "router", "modem", "external hard drive", 
	  "usb flash drive", "wireless earbuds", "vr headset", "drone", "gps navigation system",
	   "home security system", "smart home devices", "e-book reader",
	    "power bank", "robot", "vacuum cleaner" };
    
    
    
    string playerName;
    highScore = readHighScore(playerName);
    cout << "\t\t\t\t\t\t\t\t Welcome, " << playerName << "! Your current high score: " << highScore << endl;
    score = 0;
    lives = 5;
}

    void instructions() {
    	
        cout << "\t\t\t\t\t\t\t\t Welcome to ZTYPE!\n" << endl;
        cout << "\t\t\t\t\t\t\t\t Type the words that appear on the screen.\n" << endl;
        cout << "\t\t\t\t\t\t\t\t You have " << lives << " lives." << endl;

        cout << "\t\t\t\t\t\t\t\t Good luck!\n" << endl;
    }

 int readHighScore(string& playerName) {
    int highScore = 0;
    ifstream infile("high_score.txt");
    if (infile) {
        infile >> playerName >> highScore;
        infile.close();
    }
    return highScore;
}


    void saveScoreToFile(const string& playerName) {
    ofstream outfile("high_score.txt");
    if (outfile) {
        outfile << playerName << " " << score;
        outfile.close();
        cout << "\t\t\t\t\t\t\t\t Congratulations, " << playerName << "! New high score: " << score << endl;
    }
}



   void updateHighScore() {
    if (score > highScore) {
        string playerName;
        cout << "\t\t\t\t\t\t\t\t You achieved a new high score!" << endl;
        cout << "\t\t\t\t\t\t\t\t Please enter your name: ";
        cin >> playerName;
        saveScoreToFile(playerName);
    }
}



    void start() {
       
        random_shuffle(words.begin(), words.end());
        string input;
        for (const string& word : words) {
            cout << "\t\t\t\t\t\t\t\t Incoming word : " << endl;
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
                    Beep(1000, 500);
                    score += 10;
                }
                else {
                	cout << "\a" << endl;
                    cout << "\t\t\t\t\t\t\t\t Incorrect, try again." << endl;
                    lives--;
                }
            }

            if (lives == 0) 
			{cout << endl;
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
            	
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
                cout << "\t\t\t\t\t\t\t\t Game Over!" << endl;
                cout << "\t\t\t\t\t\t\t-----------------------" << endl;
               
            }
            system("cls");
            cout << "\t\t\t\t\t\t\t Your score is: " << score << "  Lives left: " << lives << endl;
        }
        updateHighScore();
    }
};





int main() {
    system("color 0A");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    
    cout << "\t\t\t\t\t\t\t_______________________________________________________________" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t__________________________.___._____________________\n";
    cout << "\t\t\t\t\t\t\t\t\\____    /\\__    ___/\\__  |   |\\______   \\_   _____/\n";
    cout << "\t\t\t\t\t\t\t\t  /     /   |    |    /   |   | |     ___/|    __)_ \n";
    cout << "\t\t\t\t\t\t\t\t /     /_   |    |    \\____   | |    |    |        \\\n";
    cout << "\t\t\t\t\t\t\t\t/_______ \\  |____|    / ______| |____|   /_______  /\n";
    cout << "\t\t\t\t\t\t\t\t        \\/            \\/                         \\/ \n";
    cout << "\t\t\t\t\t\t\t_______________________________________________________________" << endl;
    cout << endl;
    cout << endl;

    cout << "\t\t\t\t\t\t\t\t\t\t Welcome To Ztype!" << endl;
    cout << endl;

    cout << "\t\t\t\t\t\t\t\t\t Press Enter To Continue " << endl;
    cin.get();
    system("cls");

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t__________________________________" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t Menu " << endl;
    cout << "\t\t\t\t\t\t\t\t__________________________________" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t Hint:" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t Press 1 for Instructions, 2 to Start Game and 3 to Exit" << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    int choice;

    while (true) {
        cout << "\t\t\t\t\t\t\t\t 1. Instructions" << endl;
        cout << "\t\t\t\t\t\t\t\t 2. Start" << endl;
        cout << "\t\t\t\t\t\t\t\t 3. Exit" << endl;
        cin >> choice;
        system("cls");

        switch (choice) {
            case 1:
                ZtypeGame_Easy().instructions();
                break;

            case 2:
                int category;
                while (true) {
                    cout << "\t\t\t\t\t\t\t\t Choose game category" << endl;
                    cout << "\t\t\t\t\t\t\t\t 1. Music" << endl;
                    cout << "\t\t\t\t\t\t\t\t 2. Sport" << endl;
                    cout << "\t\t\t\t\t\t\t\t 3. Electronic" << endl;
                    cin >> category;
                    switch (category) {
                        case 1: {
                            int mode;
                            while (true) {
                                cout << "\t\t\t\t\t\t\t\t Select Mode" << endl;
                                cout << "\t\t\t\t\t\t\t\t 1. Easy" << endl;
                                cout << "\t\t\t\t\t\t\t\t 2. Medium" << endl;
                                cout << "\t\t\t\t\t\t\t\t 3. Hard" << endl;
                                cin >> mode;
                                switch (mode) {
                                    case 1:
                                        ZtypeGame_Easy().start();
                                        break;
                                    case 2:
                                        ZtypeGame_Medium().start();
                                        break;
                                    case 3:
                                        ZtypeGame_Hard().start();
                                        break;
                                    default:
                                        cout << "\t\t\t\t\t\t\t\t Invalid choice, please try again." << endl;
                                }
                                cout << "\t\t\t Play Again? (1 = Yes, 0 = No): ";
                                int playAgain;
                                cin >> playAgain;
                                
                                if (playAgain == 0) {
                                	return 0;
                                
                                }
                            }
                            break;
                        }

                        case 2: {
                            int mode;
                            while (true) {
                                cout << "\t\t\t\t\t\t\t\t Select Mode" << endl;
                                cout << "\t\t\t\t\t\t\t\t 1. Easy" << endl;
                                cout << "\t\t\t\t\t\t\t\t 2. Medium" << endl;
                                cout << "\t\t\t\t\t\t\t\t 3. Hard" << endl;
                                cin >> mode;
                                switch (mode) {
                                    case 1:
                                        ZtypeGame_Easy().start();
                                        break;
                                    case 2:
                                        ZtypeGame_Medium().start();
                                        break;
                                    case 3:
                                        ZtypeGame_Hard().start();
                                        break;
                                    default:
                                        cout << "\t\t\t\t\t\t\t\t Invalid choice, please try again." << endl;
                                }
                                cout << "\t\t\t\t\t\t\t\t Play Again? (1 = Yes, 0 = No): ";
                                int playAgain;
                                cin >> playAgain;
                                if (playAgain == 0) {
                                    break;
                                }
                            }
                            break;
                        }

                        case 3: {
                            int mode;
                            while (true) {
                                cout << "\t\t\t\t\t\t\t\t Select Mode" << endl;
                                cout << "\t\t\t\t\t\t\t\t 1. Easy" << endl;
                                cout << "\t\t\t\t\t\t\t\t 2. Medium" << endl;
                                cout << "\t\t\t\t\t\t\t\t 3. Hard" << endl;
                                cin >> mode;
                                switch (mode) {
                                    case 1:
                                        ZtypeGame_Easy().start();
                                        break;
                                    case 2:
                                        ZtypeGame_Medium().start();
                                        break;
                                    case 3:
                                        ZtypeGame_Hard().start();
                                        break;
                                    default:
                                        cout << "\t\t\t\t\t\t\t\t Invalid choice, please try again." << endl;
                                }
                                cout << "\t\t\t\t\t\t\t\t Play Again? (1 = Yes, 0 = No): ";
                                int playAgain;
                                cin >> playAgain;
                                if (playAgain == 0) {
                                    break;
                                }
                            }
                            break;
                        }

                        default:
                            cout << "\t\t\t\t\t\t\t\t Invalid choice, please try again." << endl;
                    }
                    cout << "\t\t\t\t\t\t\t\t Play Again? (1 = Yes, 0 = No): ";
                    int playAgain;
                    cin >> playAgain;
                    if (playAgain == 0) {
                        break;
                    }
                }
                break;

            case 3:
                return 0;
                
            default:
                cout << "\t\t\t\t\t\t\t\t Invalid choice, please try again." << endl;
        }
    }

    return 0;
}





