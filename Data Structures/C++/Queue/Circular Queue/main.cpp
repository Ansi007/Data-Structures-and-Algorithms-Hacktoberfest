#include "node.cpp"
#include <iostream>

using namespace std;

class Tree {
public:

    int *values ;
    int size;
    int noofnodes ;

    Tree () { noofnodes = 1 ; size = 50 ;
    values = new int[50] ;
    }

    Tree(int *a , int size) {
        int i;
        this->size = 50 ;
        noofnodes = size ;
        values = new int[50] ;
        for (i = 1 ; i <= noofnodes ; i++) 
            values[i] = a[i-1] ;
        
        }

    void insertion(int value) {
        if (noofnodes < size) {
            values[noofnodes++] = value ;
            
        }
        else cout << "Tree is full\n" ;
            

    }

    int deletion(int index) {
        int temp = values[index] ;
        values [index] = values [size - 1] ;
        size -- ;
        return temp ;
    }

    void print() {
        int i ;
        for (i = 1 ; i <= noofnodes ; i++)
            cout << values[i] << ' ' ;
        cout << endl ;
    }

    void findpath() {
        int i;
        for (i = 1 ; i <= noofnodes ; i++) {
            if (i*2 > noofnodes) {
                int j = i ;
                while (j > 0) {
                    cout << values[j] << " " ;
                    j = j / 2 ;

                }
                cout << endl ;
            }

        }
    }

    Tree convmatotree(int *arr , int s) {
        Tree t1;
        for (int i = 1 ; i <= s ; i++) {
            t1.insertion(arr[i-1]) ;
        }
        t1.noofnodes = s ;
            
        return t1;
    }


};

int main() {
    int arr[7] = {1 ,2,  3, 4, 5, 6, 7};
    Tree t(arr, 7) ;
    t.findpath() ;
    cout << "Data of node is: \n" ;
    t.print() ;
    t.insertion(40) ;
    t.print() ;
    int temp = t.deletion(2) ;
    cout << temp << endl;
    t.print() ;
    Tree t2 , res;
    res = t2.convmatotree(arr, 7) ;
    res.print() ;

    


}