#include "ADT.h"
#include "Stack.h"

Stack::Element::Element(int value = 0, Element* pointer = nullptr)
{
    this->value = value;
    next = pointer;
}

Stack::Stack()
{
    _root = nullptr;
    _current = nullptr;
}

void Stack::push(int value)
{
    if (_root == nullptr)
    {
        Element* temp = new Element(value, nullptr);
        _root = temp;
    }
    else
    {
        Element* temp = new Element(value, _root);
        _root = temp;
    }
}

int Stack::pop()
{
    int data = 0;

    if (_root != nullptr)
    {
        data = _root->value;
        _current = _root;
        _root = _root->next;

        delete _current;
        _current = _root;
    }
    else
    {
        //except
    }
    return data;
}

int Stack::get()
{
    int data = 0;

    if (_root != nullptr)
    {
        data = _root->value;
    }
    else
    {
        //except
    }
    return data;
}

bool Stack::isEmpty()
{
    if (_root == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack::clear()
{
    if (_root != nullptr)
    {
        while (!isEmpty())
        {
            pop();
        }
    }
}

Stack::~Stack()
{
    clear();
}

std::string Stack::toString()
{
    std::string temp = "";

    if (_root != nullptr)
    {
        temp += "{ ";
        _current = _root;
        while (_current != nullptr)
        {
            temp.append(std::to_string(_current->value) + " ");
            _current = _current->next;
        }
        temp += "]";
    }

    return temp;
}

/*std::string Stack::toString(std::string separators)
{
    std::string temp = "";

    if (_root != nullptr)
    {
        temp += "{ ";
        _current = _root;
        while (_current != nullptr)
        {
            temp.append(std::to_string(_current->value) + separators);
            _current = _current->next;
        }
        temp += "]";
    }

    return temp;
}*/

void Stack::reverse()
{
    if (_root != nullptr)
    {
        Stack temp;
        Element* point = new Element;
        point = nullptr;

        while (point != _root)
        {
            _current = _root;
            while (_current->next != point)
            {
                _current = _current->next;
            }
            point = _current;
            temp.push(point->value);
        }
        clear();

        while (!temp.isEmpty())
        {
            push(temp.pop());
        }
    }
    else
    {
        //except
    }
}