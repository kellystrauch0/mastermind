/* 
 * File:   Mastermind.cpp
 * Author: Kelly
 * 
 * Created on January 28, 2018, 6:03 PM
 */

#include "Mastermind.h"

Mastermind::Mastermind() {
    //initialize variables to default values
    Answer = "";
}

Mastermind::~Mastermind() {
}

void Mastermind::populateAnswer()
{
    //clear previous value of Answer (if any)
    Answer = "";
    
    //seed random number function
    srand(time(NULL));
    
    //populate letters with random characters between A and F, inclusive
    for(int i=0; i<4; i++)
    {
        //generate random int between 0 and 5, inclusive
        int randomInt = rand() % 5;

        //assign int's corresponding letter to a temp variable
        string tempLetter;
        switch(randomInt)
        {
            case 0:
                tempLetter = "A";
                break;
            case 1:
                tempLetter = "B";
                break;
            case 2:
                tempLetter = "C";
                break;
            case 3:
                tempLetter = "D";
                break;
            case 4:
                tempLetter = "E";
                break;
            default: //5
                tempLetter = "F";
                break;
        }
        
        //append the temp variable to the end of Answer
        Answer = Answer + tempLetter;
    }
}

void Mastermind::populateTestAnswer()
{
    Answer = "ABCD";
}

void Mastermind::printAnswer()
{
    cout << Answer;
}

string Mastermind::calculateXsAndOs(string guess)
{
    //create local copy of answer to modify within this function
    string answer = Answer;
    
    //create "backup" copy of original guess to use later
    string originalGuess = guess;
    
    //create blank string to add all necessary "x"s to
    string Xs = "";
    
    //calculate Xs
    for(int i=0; i<4; i++)
    {
        if(answer[i] == guess[i])
        {
            answer[i] = 'X';
            guess[i]  = 'x';
            Xs        = Xs + "x";
        }
    }
    
    //create blank string to add all necessary "o"s to
    string Os = "";
    
    //calculate Os
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(answer[i] == guess[j])
            {
                answer[i] = 'O';
                guess[j]  = 'o';
                Os        = Os + "o";
            }
        }
    }
    
    //create result to return
    string result = originalGuess + " " + Xs + Os + "\n";
    return result;
}