// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Question:You are given an; array of integer in which each subsequent value is not less than the previous value
//Write a Function that takes this array as an input and returns a new array with a square of each numbers sorted
//in ascending order

#include <iostream>
using namespace std;

int main()
{
    int i, n,j;
    cout << "Enter total number of elements:" << "\n";
    cin >> n;
    int* a = new int(n);
    cout << "Enter " << n << " elements" << endl;
    for (i = 0;i < n;i++) {
        cin >> a[i];
    }
    //Squraing numbers
    //for (i = 0;i < n;i++)
    //{
    //    int c = a[i] * a[i];
    //    a[i] = c;
    //}
    //Selection Sort(O(n^2)T and O(1)S)
    //for (i = 0;i < n - 1;i++)
    //{
    //    for (j = i + 1;j < n;j++)
    //    {
    //        if (a[j] < a[i])
    //        {
    //            int temp = a[j];
    //            a[j] = a[i];
    //            a[i] = temp;
    //        }
    //    }
    //}
   
    //Using the fact that array will be in ascending order:O(n) t&S
    int* sortedarray = new int[n];
    int startptr = 0;
    int endptr = n - 1;
    for (int i = n - 1;i >= 0;i--)
    {
        int leftsquare = a[startptr]*a[startptr];
        int rightsquare = a[endptr]*a[endptr];
        if (leftsquare > rightsquare)
        {
            sortedarray[i] = leftsquare;
           startptr++;

       }
        else
        {
            sortedarray[i] = rightsquare;
            endptr--;
        }
    }
    cout << "Entered elements are: ";
    for (i = 0;i < n;i++) {
        cout << sortedarray[i] << " ";
    }
    //cout << "Entered elements are: ";
    //for (i = 0;i < n;i++) {
    //    cout << a[i] << " ";
    //}
    cout << endl;
    //delete (a);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
