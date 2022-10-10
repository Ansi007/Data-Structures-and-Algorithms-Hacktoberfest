#include <iostream>
using namespace std;

class Heap{
    int* heapArray;
public:
    Heap(int*a , int size){
        heapArray = a;
        int i; 
        for(i = 1 ; i<size ; i++)
            insert(i);
    }
void insert( int index ){ //Insert for Max Heap , it can be for min heap by changing temp < a[i/2]
    int i = index ;
    int temp =  heapArray[i]; 
    while(i > 0 and temp > heapArray[(i-1)/2]){
        heapArray[i] = heapArray[i/2];
        i = i/2;
    }
    heapArray[i] = temp;
}
void Delete(int lastindex){
    int x , i , j ,val;
    x = heapArray[lastindex];
    val = heapArray[0];
    heapArray[0] = heapArray[lastindex];
    i = 0 ;
    j = (2*i)+1;
    while(j<lastindex){
        if(heapArray[j+1] > heapArray[j] ) j = j+1;
        if(heapArray[i] < heapArray[j]){
            int temp = heapArray[i];
            heapArray[i] = heapArray[j];
            heapArray[j] = temp;

            i = j;
            j = 2*j;
        }
        else break;
    }
    heapArray[lastindex] = val;
}
void sort(int size){
    int i;
    for(i = 1; i< size ; i++)
        insert(i);
    for(i = size-1; i > 0 ; i--)
        Delete(i);
}
};

// void insert(int* a , int index ){ //Insert for Max Heap , it can be for min heap by changing temp < a[i/2]
//     int i = index ;
//     int temp =  a[i]; 
//     while(i > 0 and temp > a[i/2]){
//         a[i] = a[i/2];
//         i = i/2;
//     }
//     a[i] = temp;
// }
// void Delete(int*a , int lastindex){
//     int x , i , j;
//     x = a[lastindex];
//     a[0] = a[lastindex];
//     i = 1 ;
//     j = 2*i;
//     while(j<lastindex-1){
//         if(a[j+1] > a[j] ) j = j+1;
//         if(a[i] < a[j]){
//             int temp = a[i];
//             a[i] = a[j];
//             a[j] = temp;

//             i = j;
//             j = 2*j;
//         }
//         else break;
//     }
//     a[lastindex] = x;
// }
// void createHeap(int* a , int size){
//     int i; 
//     for(i = 1 ; i<size ; i++)
//         insert(a , i);
// }

int main(){
    int heapArray[] = {10 , 20 , 30 , 25 , 5 , 40 , 35};
    Heap heap(heapArray,7);
    heap.sort(7);
    for(auto i : heapArray)
        cout<<i<<" ";
    return 0;
}