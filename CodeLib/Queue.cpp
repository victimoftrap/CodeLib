#include "Queue.h"
Queue::Queue ()
{

}

int Queue::pop ()
{
    if (_root != nullptr) 
    {
        int var = _root->value;
        Element* _temp = _root;
        _root = _root->next;
        delete _temp;
        return var;
    }
    return 0;//throw error
}

void Queue::push (int value)
{
    if (_root == nullptr) 
    {
        _root = new Element(value,nullptr);
    }
    else 
    {
        _current = _root;
        while (_current->next != nullptr) 
        {
            _current = _current->next;
        }

    }
}

Queue::Element::Element (int value, Element* next)
{
    this->value = value;
    this->next = next;
}

