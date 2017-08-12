#pragma once
#include "ADT.h"
#include <stdexcept>

#define SListEmptyExceptMessage "Empty"

class SList : ADT
{
public:
    SList();
    SList(SList&);
    void clear();
    ~SList() override;

    void push(int) override;
    int pop() override;
    int get() override;
    bool isEmpty() override;
    std::string toString() override;

    void moveForward();
    void toBegin();
    bool isEnd();
    void pushIntoBegin(int);
    void reverse() noexcept;

    void swap(SList&) noexcept;
    void merge(SList&);

    class SListIsEmptyException : public std::runtime_error
    {
    public:
        SListIsEmptyException(const std::string& what_arg) : runtime_error(what_arg){}
        SListIsEmptyException(const char* what_arg) : runtime_error(what_arg){}
        SListIsEmptyException() : runtime_error(SListEmptyExceptMessage){}
    };

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