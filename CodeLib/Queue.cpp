#include "Queue.h"
Queue::Queue ()
{

}

int Queue::pop ()
{
    if (root != nullptr) 
    {
        int var = root->value;
        Element* temp = root;
        root = root->next;
        delete temp;
        return var;
    }
    return 0;//throw error
}

void Queue::push (int value)
{
    if (root == nullptr) 
    {
        root = new Element(value,nullptr);
        current = root;
    }
    else 
    {
        current->next = new Element (value, nullptr);
        current = current->next;
    }
}

Queue::Element::Element (int value, Element* next)
{
    this->value = value;
    this->next = next;
}

int Queue::get ()
{
    return root->value;
}

bool Queue::isEmpty ()
{
    if (root == nullptr)return true;
    else return false;
}

std::string Queue::toString ()
{
    std::string result="";
    char a[10];
    if (isEmpty ())return result;
    else 
    {
        current = root;
        while (current->next != nullptr) 
        {
            _itoa_s (current->value, a, 10);
            result += a;
            result += " ";
            current = current->next;
        }
        _itoa_s (current->value, a, 10);
        result += a;
        result += " ";
    }
    return result;
}

void Queue::reverse ()
{
    Element* temp = nullptr;
    Element* temp2 = nullptr;
    bool isLast = false;
    bool first = true;
    while (!isLast)
    {
        if (root == current)isLast = true;
        if (first)
        {
            temp = root;
            root = root->next;
            temp2 = root->next;
            root->next = temp;
            temp->next = nullptr;
            temp = root;
            first = false;
        }
        else
        {
            root = temp2;
            temp2 = temp2->next;
            if (root == current)isLast = true;
            root->next = temp;
            temp = root;
        }
    }    
    current = root;
    while (current->next != nullptr)current = current->next;
}

Queue::~Queue ()
{
    if (root != nullptr)
    {
        while (root->next != nullptr)
        {
            Element* temp = root;
            root = root->next;
            delete temp;
        }
        delete root;
    }
}