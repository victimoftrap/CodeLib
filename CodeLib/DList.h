#pragma once
#include "ADT.h"

class DList : ADT
{
public:
    ~DList() override;
    void push(int) override;
    int pop() override;
    int get() override;
    bool isEmpty() override;
    std::string toString() override;
protected:
    /*
    * Structure that represent a single element of Double-Linked List.
    * It's differ from others so it cannot be put in ADT interface;
    */
    struct  Element
    {
        int value = 0;
        Element* next = nullptr;
        Element* prev = nullptr;
        Element(int, Element*,Element*);
    };
    Element* _root = nullptr;     // root element for queue.
    Element* _current = nullptr;


};