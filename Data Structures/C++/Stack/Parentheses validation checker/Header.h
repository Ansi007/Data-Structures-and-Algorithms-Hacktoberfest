#pragma once

template <class Element>
class MyStack
{
    Element* stack;      //array to implement stack
    Element* temp_stack; //temporary stack to keep a copy of actual stack while resizing
    int size;    //size of stack       
    int top_of_stack; //points to top of stack

public:
    int end = 0;
    MyStack(int s)
    {
        size = s;
        top_of_stack = -1;
        stack = new Element[size];
        temp_stack = new Element[size];
        for (int i = 0; i < size; i++) {
            stack[i] = 0;
            temp_stack[i] = 0;
        }
    }
    bool isFull();
    bool isEmpty();
    void push(Element value);
    Element pop();
    Element top();
    void resize(int prev_size, int change);
    void printStack();
    ~MyStack()
    {
        if (end == 1)
        {
            delete[] stack;
            delete[] temp_stack;
        }
    }
};