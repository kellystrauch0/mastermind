/* 
 * File:   main.cpp
 * Author: Kelly
 *
 * Created on January 28, 2018, 6:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
#include "Mastermind.h"

using namespace std;

int main(int argc, char** argv) {
    //declare variables to track this game
    int turns     = 0;
    bool gameOver = false;
    
    //create new instance of Mastermind
    Mastermind game;
    
    //populate the sequence of four letters to be guessed
    game.populateAnswer();
    
    //create string to welcome user and print instructions -- note that output
    //is intentionally pushed to the bottom of the screen each time since that's
    //the only way I have to "clear" the screen
    string instructions = string(75, '\n');
    instructions += "Welcome to Mastermind!\n\n";
    instructions += "***************************************\n\n";
    instructions += "x = black peg (right color, right spot)\n";
    instructions += "o = white peg (right color, wrong spot)\n\n";
    instructions += "Enter q at any time to quit.\n\n";
    
    //create string to remind user which letters they're allowed to use, then
    //to store user's guesses + the result of each guess
    string guessHistory = "  A | B | C | D | E | F\n\n";
    
    //print instructions to start game
    cout << instructions;
    cout << "What's your first guess?\n";
    cout << guessHistory;
    
    
    //print answer (for debugging only)
    //cout << "DEBUG MODE -- The answer is: ";
    //game.printAnswer();
    //cout << "\n\n";
    
    
    //start game loop
    while(!gameOver)
    {
        //increment turn count
        turns++;
        
        //get player's guess
        string guess;
        cin >> guess;
        
        if(guess == "q" || guess == "Q")
            return 0;
        
        //calculate Xs and Os
        string result = game.calculateXsAndOs(guess);

        //add to guess history
        guessHistory = guessHistory + result;
        
        //print instructions again, followed by newly updated guess history
        cout << instructions;
        cout << "What's your next guess?\n";
        cout << guessHistory;

        //if result has xxxx at the end, game has been won
        if(result.find("xxxx") == 5)
        {
            gameOver = true;
            cout << endl;
            cout << "  YES!  You guessed the answer in " << turns << " turns.";
            cout << endl;
        }    
    }
    
    return 0;
}