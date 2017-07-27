#pragma once
#include <string>

/*
 * Abstract data type interface. Should be based for all classes
 * that implements abstract data structure.
 */
class ADT
{
public:
    virtual ~ADT() = default;
    virtual void push(int) = 0;
    virtual int pop() = 0;
    virtual int get() = 0;
    virtual bool isEmpty() = 0;
    virtual std::string toString() = 0;
};