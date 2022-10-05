
//BSEF19M003
//LAIBA KAMAL
#include "XorDLL.h"

template<class T>
XorDLL<T>::XorDLL()//constructor
{
	head = tail = NULL;
}
//BSEF19M003
//LAIBA KAMAL
template<class T>
XorDLL<T>::XorDLL(XorNode<T>* h, XorNode<T>* t)//parameterized constructor
{
	head = h; tail = t;
}
//BSEF19M003
//LAIBA KAMAL
template<class T>
bool XorDLL<T>::isEmpty()
{
    return head == NULL;
}
//BSEF19M003
//LAIBA KAMAL
template<class T>
void XorDLL<T>::insertAtHead(T value)
{
    XorNode<T>* call = new XorNode<T>();
    XorNode<T>* newNode = new XorNode<T>();
    //set the data of new node
    newNode->data = value;
    if (isEmpty())
    {
       tail = newNode;
    }
    //set npx of new node
    //npx of new node is the XOR of current head and NULL
    newNode->npx = head;

    if (head != NULL)
    {
        //set npx of current head
        //npx of current head is the XOR of address of new node and address of next of current head
        //addr of next of current head is the XOR of NULL and npx of curr head
        head->npx = call->XOR(newNode, head->npx);
    }

    //set head
    head = newNode;
}
//BSEF19M003
//LAIBA KAMAL
template<class T>
void XorDLL<T>::insertAtTail(T value)
{
    XorNode<T>* call = new XorNode<T>();
     XorNode<T>* newNode = new XorNode<T>();
    //set the data of new node
    newNode->data = value;
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        newNode->npx = tail;
        tail->npx = call->XOR(newNode, tail->npx);
    }
    tail = newNode;
}
//BSEF19M003
//LAIBA KAMAL
template<class T>
int XorDLL<T>::removeAtHead()
{
    XorNode<T>* call = new XorNode<T>();
    int val = head->data;
    if (!isEmpty())
    {
        XorNode<T>* temp = head;
        head = temp->npx;
        head->npx = call->XOR(temp, head->npx);
        delete temp;
        if (isEmpty())
            tail = NULL;
    }
    return val;
}
//BSEF19M003
//LAIBA KAMAL
template<class T>
int XorDLL<T>::removeAtTail()
{
    XorNode<T>* call = new XorNode<T>();
    int val = tail->data;
    if (!isEmpty())
    {
        XorNode<T>* temp = tail;
        if (head->npx == NULL)
            delete head;
        else
        {
            tail = temp->npx;
            tail->npx = call->XOR(tail->npx, temp);
            delete temp;
        }
    }
    return val;
}
//BSEF19M003
//LAIBA KAMAL
template<class T>
void XorDLL<T>::printList()
{
    XorNode<T>* call = new XorNode<T>();
    XorNode<T>* temp = head;
    XorNode<T>* prev = NULL;
    XorNode<T>* next;

    cout << "NULL <-- ";
    while (temp)
    {
        cout << temp->data << " <=> ";
        next = call->XOR(prev, temp->npx);
        prev = temp;
        temp = next;
    }
    cout <<  " --> NULL" << endl;

}
//BSEF19M003
//LAIBA KAMAL
template<class T>
bool XorDLL<T>::search(T key)
{
    XorNode<T>* call= new XorNode<T>();
    XorNode<T>* temp = head;
    XorNode<T>* prev = NULL;
    XorNode<T>* next = NULL;

    while (temp)
    {
        if (temp->data == key)
        {
            cout << "Value " << key << " is found at " << temp << " in the linked list.\n";
            return true;
        }
        else
        {
            next =call-> XOR(prev, temp->npx);
            prev = temp;
            temp = next;
        }
    }
    cout << "Value " << key << " is NOT found in the linked list.\n";
    return false;
}

//BSEF19M003
//LAIBA KAMAL