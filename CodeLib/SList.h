#pragma once
#include "ADT.h"
class SList : ADT
{
public:
    SList();
    ~SList() override;
    void push(int) override;
    int pop() override;
    int get() override;
    bool isEmpty() override;
    std::string toString() override;

    void clear();
    void moveForward();
    void toBegin();
    bool isEnd();
    void pushRoot(int);

    void reverse();
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
    Element* root = nullptr;     // root element for SList.
    Element* current = nullptr;


};