#ifndef HASHMAPS
#define HASHMAPS

#include<iostream>
#include<cstring>
#include "Meal.cpp"
#include<math.h>

using namespace std;

template <class T>
class HNode{
public:
    string key;
    T* entity;
    HNode* next;
    HNode* previous;

    HNode(){}

    HNode(string key, T* entity, HNode* next = NULL, HNode* previous = NULL)
    {
        this->key = key;
        this->entity = entity;
        this->next = next;
        this->previous = previous;
    }

};

template <class T>
class HashMap{
    HNode<T>** hashTable;
    int maxNodes;
    int nodesCount;
    int *entitesCount;

    int hashFunction(string key)
    {
        int power = 1, i, index = 0;
        for(i=0; i<key.length(); i++)
        {
            index += (int)key[i] * pow(2, power++);
        }
        return index % maxNodes;
    }

    void resizeHashTable(int maxNodes)
    {
        int i;
        int* tempEntitesCount = new int[maxNodes];
        HNode<T>** tempHashTable = new HNode<T> * [maxNodes];
        for(i=0; i<this->maxNodes; i++) {
            tempHashTable[i] = hashTable[i];
            tempEntitesCount[i] = entitesCount[i];
        }
        for( ; i<maxNodes; i++)
        {
            tempHashTable[i] = NULL;
            tempEntitesCount = 0;
        }
        hashTable = tempHashTable;
        this->maxNodes = maxNodes;
        delete[] entitesCount;
        entitesCount = tempEntitesCount;
    }

public:
    HashMap(int n = 30)
    {
        if(n <= 0)
            n = 30;
        nodesCount = 0;
        maxNodes = n;
        entitesCount = new int[maxNodes];
        hashTable = new HNode<T> * [maxNodes];
        for(int i=0; i<maxNodes; i++) {
            hashTable[i] = NULL;
            entitesCount[i] = 0;
        }
    }

    void addMeal(string key, T* entity) {
        if (nodesCount == maxNodes - 1)
            resizeHashTable(maxNodes * 2);

        int index = hashFunction(key);
        for (; hashTable[index] != NULL && hashTable[index]->key != key; index = (++index) % maxNodes);

        if (hashTable[index] == NULL) {
            hashTable[index] = new HNode<T>(key, entity);
        } else if (hashTable[index]->key == key) {
            HNode<T> *temp;
            for (temp = hashTable[index]; temp->next != NULL; temp = temp->next);
            temp->next = new HNode<T>(key, entity);
            temp->next->previous = temp;
        } else {
            throw invalid_argument("Unexpected Error Occured at addNode() of HashMap class!!\n");
        }
    }

    Meal* getMealbyName(string key, string name)
    {
        HNode<T>* node;
        int index = hashFunction(key);
        for (; hashTable[index] != NULL && hashTable[index]->key != key; index = (++index) % maxNodes);
        if(hashTable[index] == NULL)
        {
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "<-----------------No Meals Available------------------->\n\n";
            return NULL;
        }
        for(node = hashTable[index]; node != NULL && node->entity->getMealName() != name; node=node->next);
        if(node == NULL) {
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "<-----------------No Meals Available------------------->\n\n";
            return NULL;
        }
        return node->entity;
    }

    T* getMealbyName(string name)
    {
        int i=0;
        HNode<T>* node;
        for(i=0; i<maxNodes; i++)
        {
            for(node = hashTable[i]; node != NULL; node = node->next)
            {
                if(node->entity->getMealName() == name)
                    return node->entity;
            }
        }
        return NULL;
    }

    bool deleteMeal(string key, string name)
    {
        HNode<T>* node, *temp;
        int index = hashFunction(key);
        for (; hashTable[index] != NULL && hashTable[index]->key != key; index = (++index) % maxNodes);
        if(hashTable[index] == NULL)
        {
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "<-----------------No Meals Available------------------->\n\n";
            return false;
        }
        if(hashTable[index]->entity->getMealName() == name)
        {
            temp = hashTable[index];
            hashTable[index] = hashTable[index]->next;
        }
        else{
            for(node = hashTable[index]; node != NULL && node->entity->getMealName() != name; node = node->next);
            if(node == NULL)
            {
                cout << "\n\n\t\t\t\t\t\t\t\t";
                cout << "<-----------------No Meals Available------------------->\n\n";
                return false;
            }
            if(node->next != NULL)
                node->next->previous = node->previous;
            node->previous->next = node->next;
            temp = node;
        } 
        delete temp;
        return true;
    }

    void showMealsBySearch(string type)
    {
        int i=0;
        HNode<T>* node;
        for(i=0; i<maxNodes; i++)
        {
            for(node = hashTable[i]; node != NULL; node = node->next)
            {
                if(node->entity->getTypeOfMeal() == type)
                    node->entity->displayList();
            }
        }
    }

    void printMealsByID(string key)
    {
        HNode<T>* node;
        int index = hashFunction(key);
        for (; hashTable[index] != NULL && hashTable[index]->key != key; index = (++index) % maxNodes);
        if(hashTable[index] == NULL)    
            cout << "\nKey does not exist\n";
        else{
            for(node = hashTable[index]; node != NULL; node = node->next)
                node->entity->stdOut(cout, false);
        }
    }

    void printMealsList(string key, string resName = "", string header = "", bool isCLS = true)
    {
        HNode<T>* node;
        int index = hashFunction(key);
        for (; hashTable[index] != NULL && hashTable[index]->key != key; index = (++index) % maxNodes);
        if(hashTable[index] == NULL) {
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "<-----------------No Meals Available------------------->\n\n";
        }
        else{
            if(isCLS){
                system("cls");
                cout << header;
            }
            cout << "\n\n\t\t\t\t\t\t\t\t|---->   Restaurant: " << resName << " <----|\n";
            cout << "\n\n\t\t\t\t\t\t\t\t|---->   MEALS LIST   <----|\n\n";
            for(node = hashTable[index]; node != NULL; node = node->next)
                node->entity->displayList();
        }
    }


    ostream& stdOut(ostream& out, bool isFile = false)
    {
        int i=0;
        HNode<T>* node;
        for(i=0; i<maxNodes; i++)
        {
            for(node = hashTable[i]; node != NULL; node = node->next)
            {
                node->entity->stdOut(out, isFile);
            }
        }
        return out;
    }

};

#endif