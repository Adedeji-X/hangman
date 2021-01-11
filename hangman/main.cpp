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


int main() {
   // int user_lives = 7;
   /* while (user_lives > 0){
        
    }*/
    return generated_numbers();
    

}

string get_word()
{
    const int SIZE_OF_WORD = 10;
    string temp_word;
    string wordlist[SIZE_OF_WORD] = {""};
    
    fstream input_file("/Users/cloud/Documents/cpp/hangman/wordlists.txt");
    if (!input_file) {
        cout << "Error: -2 word list not located" << endl;
    }
    return 0;
}

void print_board(int lives){
    
}

void print_blanks(string choosen_word, string letter_guessed)
{
    
}

int generated_numbers()
{
    srand((unsigned int) time(NULL));
    int randon_number = rand() % 10 + 1;
    return randon_number;
}
