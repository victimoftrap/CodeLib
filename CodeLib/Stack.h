#pragma once
#include "ADT.h"
/*
 * This class implements ADT interface. This means, that he must define
 * and implement all methonds listed in ADT
 */
class Stack : ADT
{
public:
    ~Stack() override;
    void push(int) override;
    int pop() override;
    int get() override;
    bool isEmpty() override;
    std::string toString() override;
    void reverse();

protected:
    /*
     * Structure that represent a single element of Stack. 
     */
    struct  Element
    {
        int value = 0;
        Element* next = nullptr;
        Element(int, Element*);
    };
    Element* _root = nullptr;     // root element for stack.
    Element* _current = nullptr;  // ideal realization should not contain this field.
    

    


};