/**
 * @file SLLString.cpp
 * @author Christopher Liudahl-Rackley
 * @brief This is a program that implements a C-style string as a 
 * linked list as opposed to the conventional array based cstyle string
 * @date 2021-10-25
 */

#include <iostream>
#include "SLLString.h"


Node *SLLString::newList(char c)
{
    Node *list = new Node(c, nullptr);
    return list;
}

// default constructor
SLLString::SLLString() : head(newList('\0')) {}

//@params: other, which is a c++ string
SLLString::SLLString(const std::string &other)
{
    head = new Node('\0', nullptr);
    Node *first = head->next; // use this pointer to modify without loosing the link of the original
    first = new Node(other.at(0), nullptr);
    head->next = first;

    // create a new node for each character that is used as input
    for (int i = 1; i <= other.length() - 1; i++)
    {
        first->next = new Node(other.at(i), nullptr);
        first = first->next;
    }
}

//copy constructor
SLLString::SLLString(const SLLString &other)
{
    // create a new node and will dereference the value of the instance and assigning it to the new node, I believe this is to do the deepcopy.
    head = newList('\0');
    *this = other;
}
/**
 * @brief Destroy the SLLString::SLLString object
 * My optimal solution I was thinking would be to reverse the linked
 * list in order to delete the nodes in reverse order.
 * Did not choose to go that route of using multiple pointer nodes,
 * but thought it would have been a good method.
 */
SLLString::~SLLString()
{
    Node *p = this->head->next;
    //goes through the list one by one and deletes the nodes
    while (p->next != nullptr)
    {
        if (p->next->next == nullptr)
        {
            p->next = nullptr;
            delete p->next;
        }
        else
        {
            Node *nextNode = p->next;
            p->next = nextNode->next;
            delete nextNode;
        }
    }
    // then once it has finished the iteration it deletes the remaining that it started out on with.
    delete p;
    delete head;
}
//assignment operator
SLLString &SLLString::operator=(const SLLString &other)
{
    if (this != &other)
    {
        Node *otherhead = other.head;
        Node *otherFirst = otherhead->next;
        head = newList('\0');
        Node *current = head->next;
        current = newList(otherFirst->character);
        head->next = current;
        while (otherFirst->next != nullptr)
        {
            otherFirst = otherFirst->next;
            current->next = newList(otherFirst->character);
            current = current->next;
        }
    }
    return *this;
}
int SLLString::length() const
{
    int strLength = 0;
    Node *currentFirst = this->head->next;
    //add to strLength variable, then return at end
    while (currentFirst != nullptr)
    {
        strLength++;
        currentFirst = currentFirst->next;
    }
    return strLength;
}

//modifying object, thus calls destructor
SLLString &SLLString::operator+=(const SLLString &other)
{
    // set a pointer at beginning as to not loose the connection of the links. Iterate through string, brings current to end of "this"instances string.
    Node *current = this->head->next;
    while (current->next != nullptr)
        current = current->next;
    // Create a new pointer that iterates though the "other" string and then add new Node with the characters of "other" string and add them

    Node *secondHead = other.head->next;
    for (int i = 0; i < other.length(); i++)
    {
        Node *newCharacter = newList(secondHead->character);
        current->next = newCharacter;
        current = current->next;
        secondHead = secondHead->next;
    }
    return *this;
}

//find the character at index n
char &SLLString::operator[](const int n) const
{
    Node *current = head->next;
    for (int i = 0; i < n; i++)
        current = current->next;
    return current->character;
}

int SLLString::findSubstring(std::string str)
{
    //if input is c++ string, put str as parameter of SLLstr object.
    return findSubstringHelper(SLLString(str));
}

//find substring within the string
int SLLString::findSubstringHelper(const SLLString &substring)
{
    Node *current = this->head->next;
    int index = 0;
    bool isSubstring = false;
    int substringIndex = -1;
    while (current != nullptr)
    {
        if (current->character == substring.operator[](0))
        {
            substringIndex = index;
            Node *temp = current;
            for (int i = 0; i < substring.length(); i++)
            {
                if (temp->character == substring.operator[](i))
                {
                    isSubstring = true;
                }
                else
                    break;
                temp = temp->next;
            }
        
        }
        index++;
        current = current->next;
    }
    return substringIndex;
}

void SLLString::erase(char c)
{
    Node *current = this->head->next;
    Node *previous; //tracker pointer to modify while iterating
    while (current->next != nullptr)
    {
        if (current->next->character == c)
        {
            previous = current;          //save point for current
            Node *match = current->next; //Node match to save match point
            previous->next = match->next;
            delete match; //deleting matching node
            // last element deleted, then break from the loop
            if (previous->next == nullptr)
                break;
            else
                previous = previous->next;
        }
        else
            current = current->next;
    }
}