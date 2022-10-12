#include <iostream>

using namespace std ;

class Heap{
    int *a ;
    int size ;
    int noofnodes ;

public:
    Heap(int size) {
        int i;
        this->size = size ;
        a = new int[size] ;
        noofnodes = 0 ;
    }

    void remove ()
    {
        int temp , i , j , val;
        i = 1 ;
        j = 2* i ;
        a[i] = a[noofnodes] ;
        while (j < noofnodes) 
        {  
            if (a[j + 1] < a[j]) j++ ;
            if (a[i] > a[j]) 
            {
                swap(a[i] , a[j]) ;
                i = j ;
                j = 2 * i ;

            }
            else break ;
        }
        noofnodes -- ;

    }

    void HeapSort (int n)
    {
        int temp , i , j , val;
        temp = a[1] ;
        i = 1 ;
        j = 2* i ;
        a[i] = a[n] ;
        while (j < n ) 
        {  
            if ( a[j + 1] < a[j]) j++ ;
            if (a[i] > a[j]) 
            {
                swap(a[i] , a[j]) ;
                i = j ;
                j = 2 * i ;
            }
            else break ;
        }
        a[n] = temp ;
    }


    void insert (int data) 
    {
        a[++noofnodes] = data ;
        int temp ;
        int i = noofnodes ;
        temp = a[noofnodes];
        while (i > 1 and temp < a[i / 2]) 
        {
            a[i] = a[i / 2] ;
            i = i / 2 ;
        }
        a[i] = temp ;

    }

    void show ()
    {
        int i ;
        for (i = 1 ; i <= noofnodes ; i++)
            cout << a[i] << ' ' ;
        cout << endl ;
    }


};

int main ()
{
    int choice ;
    int values[11] = {4 , 7, 2 ,8 , 1, 14, 18, 20 , 5, 19, 1} ;
    Heap h(11) ;
    int i ;
    for (i = 0 ; i < 11 ; i++){
        h.insert(values[i]) ;
        h.show() ;
    }
        
    cout << "The values in Min Heap are\n" ;
    h.show() ;
    // cout << "Enter 1 if you want to do remove elements. Enter 2 if you want to do heap sort\n" ;
    // cin >> choice ;
    // if (choice == 1) 
    // {
        // cout << "Remove elements one by one\n" ;
        // for (int i = 1 ; i <= 11 ; i++)
        //     h.remove() ;
        //     h.show() ;
    // }
    // if (choice == 2) 
    // {
        // cout << "Heap sort\n" ;
        // for (i = 11 ; i > 0 ; i--)
        // {
        //     h.HeapSort(i) ;
        //     h.show() ;
        // }
    // }
    // else cout << "Invalid choice\n" ;

}
