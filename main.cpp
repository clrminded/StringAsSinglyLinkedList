/**
 * TITLE: String as Singly Linked List
 * @file main.cpp
 * @author Christopher Liudahl-Rackley
 * @brief This is a program that implements a C-style string as a 
 * linked list as opposed to the conventional array based cstyle string
 * @date 2021-10-25
 *
 * This one needs some work
 * PURPOSE: This assignment will help you get practice with:  
 * • Singly Linked Lists 
 * • C++ Rule of Big Tree (destructor. copy constructor. copy assignment operator) 
 * • C++ operator overloading  
 * • C++ pointers and reference variables
 * 
 * In many programming languages, the String class is typically implemented as an array of 
 * characters. Some other languages, such as Haskell, Erlang, and a few other functional 
 * programming languages, however, implement strings as Singly Linked List (SLL) of characters. 
 * Compared with the array implementations, the SLL ones are very easy for pattern matching 
 * because of the recursive structure of linked list. Let’s not worry about recursion in this assignment. 
 * 
 * TASK:
 * You are asked to: 
 * • create SLLString class and provide implementations for all functions given in the assignment description 
 * • use singly linked list to implement string as a linked list of characters 
 * • overload << operator so that cout<< works with SLLString objects 
 * • apply big three rule by implementing copy constructor, assignment operator and destructor
 * 
 */

#include <iostream>
#include "SLLString.h"

int main()
{
    SLLString str("Hello world!");
    SLLString newStr;

    newStr = str; //calls assignment operator

    newStr += SLLString(" CS@BC");

    newStr[6] = 'W';

    std::cout << newStr << std::endl; // Hello World! CS@BC

    std::cout << newStr.length() << std::endl; //18

    int loc = newStr.findSubstring("World");
    std::cout << loc << std::endl; // 6

    newStr.erase('l');      //erase the letter l.
    std::cout << newStr << std::endl; // Heo Word! CS@BC

    newStr.erase('C');
    std::cout << newStr << std::endl; // Heo Word! S@B
    return 0;
}