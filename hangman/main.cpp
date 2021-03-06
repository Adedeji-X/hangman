//
//  main.cpp
//  hangman
//
//  Created by cloud on 1/10/21.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

string get_word();
void print_board(int);
void print_blanks(string , string);
int generated_numbers();

bool flag = false;

int main() {
    
    int user_lives = 7;
    string word = get_word();
    string letter_guessed = "";
    string guess;
    while (user_lives > 0){
        flag = true;
        print_board(user_lives);
        cout << endl << endl;
        print_blanks(word, letter_guessed);
        if (flag == true) {
            break;
        }
        cout <<"\n\n Letter guessed" << letter_guessed << endl;
        cout << "\n\n Enter a letter ";
        cin >> guess;
        
        letter_guessed += guess;
        
        if( word.find(guess) != -1){

            continue;
        }
        else{

            user_lives--;
        }
    }
    
    if (user_lives == 0){
        cout << "\n\n\nYou Lose" << endl << endl;
        cout << "the word was :" << word << endl;
        
    }
    else if(user_lives > 0){
        cout << "\n\n\nYou Win" << endl << endl;
        cout << "the word was :" << word << endl;
    }
    return 0;
    

}

string get_word()
{
    const int SIZE_OF_WORD = 10;
    string temp_word;
    string wordlist[SIZE_OF_WORD] = {""};
    
    int index = 0;
    
    fstream input_file("/Users/cloud/Documents/cpp/hangman/wordlists.txt");
    if (!input_file) {
        cout << "Error: -2 word list not located" << endl;
    }
    
    input_file.ignore(255, '\n');
    
    //pre-read
    input_file >> temp_word;
    
    while (!input_file.eof()) {
        
        wordlist[index] = temp_word;
        index++;
        
    //Post-read
        input_file >> temp_word;
    }
    
    return wordlist[generated_numbers()];
}

void print_board(int lives){
    
    switch (lives) {
        case 0:
            cout << "\t\t\t| ------ |" << endl;
            cout << "\t\t\t|        0" << endl;
            cout << "\t\t\t|       /|\\" << endl;
            cout << "\t\t\t|        |" << endl;
            cout << "\t\t\t|       / \\" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|_";
            break;
        case 1:
            cout << "\t\t\t| ------ |" << endl;
            cout << "\t\t\t|        0" << endl;
            cout << "\t\t\t|       /|\\" << endl;
            cout << "\t\t\t|        |" << endl;
            cout << "\t\t\t|         \\" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|_";
            break;
        case 2:
            cout << "\t\t\t| ------ |" << endl;
            cout << "\t\t\t|        0" << endl;
            cout << "\t\t\t|       /|\\" << endl;
            cout << "\t\t\t|        |" << endl;
            cout << "\t\t\t|         \\" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|_";
            break;
        case 3:
            cout << "\t\t\t| ------ |" << endl;
            cout << "\t\t\t|        0" << endl;
            cout << "\t\t\t|       /|" << endl;
            cout << "\t\t\t|        |" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|_";
            break;
        case 4:
            cout << "\t\t\t| ------ |" << endl;
            cout << "\t\t\t|        0" << endl;
            cout << "\t\t\t|        |" << endl;
            cout << "\t\t\t|        |" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|_";
            break;
        case 5:
            cout << "\t\t\t| ------ |" << endl;
            cout << "\t\t\t|        0" << endl;
            cout << "\t\t\t|        |" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|_";
            break;
        case 6:
            cout << "\t\t\t| ------ |" << endl;
            cout << "\t\t\t|        0" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|_";
            break;
        case 7:
            cout << "\t\t\t| ------ |" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|" << endl;
            cout << "\t\t\t|_";
            break;
    }

}

void print_blanks(string choosen_word, string letter_guessed)
{
    for (int i = 0; i < choosen_word.size(); i++) {
        
        if (letter_guessed.find(choosen_word.at(i)) != -1) {
            cout << choosen_word.at(i) << " " << endl;
           
        }
        
        else{
            cout << "_" << endl;
            flag = false;
        }
    }
}

int generated_numbers()
{
    srand((unsigned int) time(NULL));
    int randon_number = rand() % 10 + 1;
    return randon_number;
}
