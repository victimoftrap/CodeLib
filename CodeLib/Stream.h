#pragma once
#include "ADT.h"

class Stream : ADT
{
public:
    ~Stream() override;
    void push(int) override;
    int pop() override;
    int get() override;
    bool isEmpty() override;
    std::string toString() override;
protected:

};