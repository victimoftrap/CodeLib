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
        /*current = root;
        while (current->next != NULL)
        {
            current = current->next;
        }*/
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
        Element* temp = new Element;
        temp = root;
        while (temp->next != current)
        {
            temp = temp->next;
        }

        if (current != nullptr) temp->next = current->next;
        else temp->next = nullptr;
        //temp->next = current->next;
        
        int data = current->value;
        delete current;
        current = root;
        return data;
    }
}

int SList::get()
{
    if (isEmpty())
    {
        //except
    }
    else if (root->next == nullptr)
    {
        return root->value;
    }
    else
    {
        return current->value;
    }
}

bool SList::isEmpty()
{
    if (root == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string SList::toString()
{
    std::string temp = "";
    if (!isEmpty())
    {
        Element* lastCurrent = new Element;
        lastCurrent = current;

        temp += "[ ";
        current = root;
        while (current != nullptr)
        {
            temp.append(std::to_string(current->value) + " ");
            current = current->next;
        }
        temp += "}";

        current = lastCurrent;
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
            current = root;
            root = root->next;
            delete current;
            current = nullptr;
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
    if (isEmpty())
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
    if (current->next == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void SList::toEnd()
{
    if (isEmpty())
    {
        //except
    }
    else
    {
        if (root->next != nullptr)
        {
            current = root;
            while (current->next != nullptr)
            {
                current = current->next;
            }
        }
    }
}

void SList::pushBegin(int value)
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
