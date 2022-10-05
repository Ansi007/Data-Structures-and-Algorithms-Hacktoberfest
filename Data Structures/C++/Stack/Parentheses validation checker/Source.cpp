#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

    template <class Element>
    bool MyStack<Element>:: isFull()
    {
        if (top_of_stack == size - 1) //if so, stack is full
            return 1;
        else
            return 0;
    }
    template <class Element>
    bool MyStack<Element>:: isEmpty()
    {
        if (top_of_stack == -1) //whenever stack is empty, top_of_stack == -1
            return 1;
        else
            return 0;
    }
    template <class Element>
    void MyStack<Element>:: push(Element value)
    {
            if (size == top_of_stack+1) //if stack is full, increase its size
                resize(size, 2);
            stack[++top_of_stack] = value;
    }
    template <class Element>
    Element MyStack<Element>:: pop()
    {
        if ((top_of_stack + 1) < (size / 4)) //if size of stack currently in use is less than 1/4 of total size, then reduce its size
            resize(size, 1);

        if (!isEmpty())
            return stack[top_of_stack--];
        else
            cout << "ERROR! Stack is empty" << endl;
    }
    template <class Element>
    Element MyStack<Element>:: top()
    {
        return stack[top_of_stack];
    }
    template <class Element>
    void MyStack<Element>:: resize(int prev_size, int change)  
    {
        for (int i = 0; i <= top_of_stack; i++) //copy original stack in temporary stack
            temp_stack[i] = stack[i];

        if (change == 1)  //reduce size by half
        {
            size = prev_size / 2;
            stack = new Element[size]; //create a new stack having size 1/2 times the original stack
            for (int i = 0; i <= top_of_stack; i++)
            {
                stack[i] = temp_stack[i];    //copy the old stack elements in resized stack
            }
        }
        else if (change == 2) //increase size by 2 times
        {
            size = prev_size * 2; 
            stack = new Element[size]; //create a new stack having size 2 times the original stack
            for (int i = 0; i < prev_size; i++) 
                stack[i] = temp_stack[i];    //copy the old stack elements in resized stack
        }
    }
    template <class Element>
    void MyStack<Element>:: printStack()
    {
        cout << "\nStack contains these elements: ";
        for (int i = top_of_stack; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
    
    int get_index(char pushed)
    {
        switch (pushed)
        {
        case '[':
            return 0;
        case '{':
            return 1;
        case '(':
            return 2;
        case ']':
            return 3;
        case '}':
            return 4;
        case ')':
            return 5;
        default:
            return -10;
        }
    }

    template <class Element>
    bool string_validation(MyStack<Element> S)
    {
        int string_length = 0;
        char popped_P;
        string expression;
        cout << "Enter the expression: ";
        cin >> expression;
        string_length = expression.length();
        if ((string_length % 2 == 1) || (get_index(expression[0]) > 2)) //if either length is odd or it starts with closing parenthesis then its invalid expression
            return 0;

        for (int i = 0; i < string_length; i++)
        {
            if (get_index(expression[i]) < 3)
            {
                S.push(expression[i]);
                if (i == 0)
                    continue;
            }
            else
            {
                popped_P = S.pop();
                if((get_index(popped_P) + 3) != (get_index(expression[i]))) //if closing parenthesis does not match with opening parenthesis then its invalid expression
                    return 0;
            }
        }
        if (S.isEmpty() == 1)
            return 1;
        else
            return 0;
    }

int main()
{
    int element = 0;
    int decide = 0;
  
    MyStack<char> stack(100);

    int check = string_validation(stack);
    if (check==1)
        cout << "\n\t\t VALID STRING";
    else
        cout << "\n\t\t INvALID STRING";
    stack.end = 1;
    return 0;
}

