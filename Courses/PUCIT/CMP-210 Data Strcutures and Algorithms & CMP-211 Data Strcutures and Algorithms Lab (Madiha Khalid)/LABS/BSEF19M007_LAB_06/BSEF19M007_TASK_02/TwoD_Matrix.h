#pragma once

/*
Array ADT Having all main functionalites of STL array. Supports N-Dimensions.
:protected members: 
=> arr is a 1D array used to support functionality from 1 to N - D.
=> size is the total size of array required.
=> D is a dynamic array which holds the record for values of all dimension. for example for 2D { what by what } is stored.
=> dimNo tells the dimension.
=> I is a dynamic array which holds current/required indeces being used. E.g. [0][3]
=> count tells the current no of values stored.
*/

template<class T>
class Array {
protected:
	T* arr;
	int size;
	int* D, dimNo;
	int* I, count;
public:
	Array();
	Array(int , ...);
	T at(int);
	void setValue(int, int);
	T front();
	T back();
	void resize();
	bool isFull();
	bool isEmpty();
	int getIndex(int , ...);
	~Array();
};

/*
TwoD_Matrix A class for 2D matrices.
This class stores the elements of the 2-D matrix in a linear array(ADT) that is created dynamically.
*/
template<class T>
class TwoD_Matrix
{
private:
	Array<T> *arr;
	int rows, cols;
	int size;
public:
	TwoD_Matrix();
	TwoD_Matrix(int,int);
	TwoD_Matrix(const TwoD_Matrix&);
	int getElement(int, int);
	void setElement(int, int, int);
	void printMatrix();
	void printMatrix(const TwoD_Matrix&);
	void transpose();
	void printSubMatrix(int, int, int, int);
	void operator + (TwoD_Matrix& M2);
	void clear(int);
	~TwoD_Matrix();
};


