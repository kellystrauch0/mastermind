/* 
 * File:   Mastermind.h
 * Author: Kelly
 *
 * Created on January 28, 2018, 6:03 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>

#ifndef MASTERMIND_H
#define MASTERMIND_H

using namespace std;

class Mastermind {
    
public:
    //constructor and destructor
    Mastermind();
    virtual ~Mastermind();
    
    //methods
    void populateAnswer();
    void printAnswer();
    void populateTestAnswer();
    string calculateXsAndOs(string guess);
    
private:
    string Answer;
};

#endif /* MASTERMIND_H */

