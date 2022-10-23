#ifndef LIST
#define LIST

#include<iostream>
#include <typeinfo>
#include <cxxabi.h>

using namespace std;

template <class T>
class List;

template <class T>
class Node{
public:
    T* entity;
    Node<T> *next;

    Node(T *entity, Node<T>* next = NULL)
    {
        this->entity = entity;
        this->next = next;
    }
};

template <class T>
class List{
    Node<T> *head;
    Node<T> *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void addNode(T* entity)
    {
        Node<T> *newNode = new Node<T>(entity);
        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    int calcPrice()
    {
        int price = 0;
        Node<T>* node;
        for(node = head; node != NULL; node = node->next)
        {
            price += node->entity->getPrice();
        }
        return price;
    }

    T* authenticateLogin(string id, string password)
    {
        Node<T>* node;
        bool isLogin;
        for(node = head; node != NULL; node = node->next) {
            isLogin = node->entity->authLogin(id, password);
            if(isLogin)
                return node->entity;
        }
        return NULL;
    }

    bool isExists(string id)
    {
        Node<T>* node;
        for(node = head; node != NULL; node = node->next)
            if(node->entity->getID() == id)
                return true;
        return false;
    }

    T* getRestaurantbyName(string name)
    {
        Node<T>* node;
        for(node = head; node != NULL; node = node->next)
            if(node->entity->getName() == name)
                return node->entity;
        return NULL;
    }

    void showNames()
    {
        Node<T>* node;
        for(node = head; node != NULL; node = node->next)
            cout << "\n\n\t\t\t\t\t\t\t\t\t-->   " <<node->entity->getName() << endl;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void viewCart()
    {
        Node<T>* node;
        for(node = head; node != NULL; node = node->next)
            node->entity->displayList();
    }

    ostream& stdOut(ostream& out, bool isFile = false)
    {
        Node<T>* node;
        for(node = head; node != NULL; node = node->next)
            node->entity->stdOut(out, isFile);
        return out;
    }
};

#endif
