/**
 * @file SLLString.h
 * @author Christopher Liudahl-Rackley
 * @brief This is a program that implements a C-style string as a
 * linked list as opposed to the conventional array based cstyle string
 * @date 2021-10-25
 */

#ifndef SLL_STRING
#define SLL_STRING

#include <iostream>
#include <string>
#include "Node.h"

class SLLString
{
private:
  char character;
  Node *head;

public:
  Node *newList(char c);
  SLLString();
  SLLString(const std::string &other);
  ~SLLString();
  SLLString(const SLLString &other);
  SLLString &operator=(const SLLString &other);
  int length() const;
  SLLString &operator+=(const SLLString &other);
  char &operator[](const int n) const;
  int findSubstringHelper(const SLLString &substring);
  int findSubstring(std::string str);
  void erase(char c);
  friend std::ostream &operator<<(std::ostream &out, const SLLString &s)
  {
    Node *temp = s.head->next;
    while (temp != nullptr)
    {

      std::cout << temp->character;
      temp = temp->next;
    }
    return out;
  }
};

#endif // SLL_STRING