#include "ADT.h"
#include "SList.h"

SList::Element::Element(int value = 0, Element* pointer = nullptr)
{
    this->value = value;
    next = pointer;
}

SList::SList()
{
    root = nullptr;
    current = nullptr;
}

void SList::push(int value)
{
    Element* temp = new Element(value, nullptr);
    if (isEmpty())
    {
        root = temp;
        current = root;
    }
    else if (current->next == nullptr)
    {
        current->next = temp;
        current = current->next;
    }
    else
    {
        temp->next = current->next;
        current->next = temp;
        current = current->next;
    }
}

int SList::pop()
{
    if (isEmpty())
    {
        //except
    }
    else if (root->next == nullptr)
    {
        int data = root->value;
        delete root;
        root = nullptr;
        current = nullptr;
        return data;
    }
    else if (current == root)
    {
        int data = root->value;
        current = root;
        root = root->next;
        delete current;
        current = root;
        return data;
    }
    else if (current->next == nullptr)
    {
        int data;
        current = root;
        while (current->next->next != nullptr)
        {
            moveForward();
        }
        data = current->next->value;
        delete current->next;
        current->next = nullptr;

        return data;
    }
    else
    {
        Element* temp = root;
        while (temp->next != current)
        {
            temp = temp->next;
        }

        temp->next = current->next;
        
        int data = current->value;
        delete current;
        current = temp;
        return data;
    }
}

int SList::get()
{
    if (isEmpty())
    {
        //except
    }
    else
    {
        return current->value;
    }
}

bool SList::isEmpty()
{
    return (root == nullptr);
}

std::string SList::toString()
{
    std::string temp = "";
    if (!isEmpty())
    {
        Element* lastCurrent = root;
        
        temp += "[ ";
        while (lastCurrent != nullptr)
        {
            temp.append(std::to_string(lastCurrent->value) + " ");
            lastCurrent = lastCurrent->next;
        }
        temp += "}";
    }
    return temp;
}

void SList::clear()
{
    if (root != nullptr)
    {
        toBegin();
        while (!isEmpty())
        {
            pop();
        }
        delete root;
        root = nullptr;
    }
}

SList::~SList()
{
    clear();
}

void SList::moveForward()
{
    if (current == nullptr)
    {
        //except
    }
    else
    {
        current = current->next;
    }
}

void SList::toBegin()
{
    if (isEmpty())
    {
        //except
    }
    else
    {
        current = root;
    }
}

bool SList::isEnd()
{
    return (current->next == nullptr);
}

void SList::pushRoot(int value)
{
    Element* temp = new Element;
    temp->value = value;
    if (isEmpty())
    {
        temp->next = nullptr;
        root = temp;
    }
    else
    {
        temp->next = root;
        root = temp;
    }
    current = root;
}

void SList::reverse()
{
    if (!isEmpty())
    {
        SList esr;
        Element* point = nullptr;

        while (point != root)
        {
            toBegin();
            while (current->next != point)
            {
                moveForward();
            }
            point = current;
            esr.push(point->value);
        }

        clear();
        esr.toBegin();
        while (!esr.isEmpty())
        {
            push(esr.pop());
        }
    }
}