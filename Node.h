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

/**
 * This is a node class, where the type of the data that is held is a character
 * +-------+---------+
 * | char  | Node*   | ----->
 * +-------+---------+
 *
 */
class Node
{
public:
  char character;
  Node *next;

  /**
   * @param: m_character - The member char element that is held in the node.
   * @param: m_next - The member Node* to point to the next address in the list.
   */
  Node(char m_character, Node *m_next)
  {
    character = m_character;
    next = m_next;
  }
};

#endif // NODE_H