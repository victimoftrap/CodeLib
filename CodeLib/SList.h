#pragma once
#include "ADT.h"
class List : ADT
{
public:
    List();
    ~List() override;
    void push(int) override;
    int pop() override;
    int get() override;
    bool isEmpty() override;
    std::string toString() override;
protected:
    /*
    * Structure that represent a single element of Single-Linked List.
    */
    struct  Element
    {
        int value = 0;
        Element* next = nullptr;
        Element(int, Element*);
    };
    Element* _root = nullptr;     // root element for SList.
    Element* _current = nullptr;


};