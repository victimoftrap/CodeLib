#pragma once
#include "ADT.h"

class Vector : ADT
{
public:
    Vector();
    ~Vector() override;
    void push(int) override;
    int pop() override;
    int get() override;
    bool isEmpty() override;
    std::string toString() override;
protected:

};
