/**
 * @file main.cpp
 * @author Christopher Liudahl-Rackley
 * @brief This is a program that implements a C-style string as a 
 * linked list as opposed to the conventional array based cstyle string
 * @date 2021-10-22
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
public:
    char character;
    Node* next;

    Node(char _character, Node* _next) {
      character = _character;
      next = _next;
    }
};

#endif // NODE_H