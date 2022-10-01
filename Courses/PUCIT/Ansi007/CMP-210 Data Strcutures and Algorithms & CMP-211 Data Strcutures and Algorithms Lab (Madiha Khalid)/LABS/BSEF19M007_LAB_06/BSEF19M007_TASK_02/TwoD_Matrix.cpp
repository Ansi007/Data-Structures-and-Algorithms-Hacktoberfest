#include "TwoD_Matrix.h"
#include<stdarg.h>
#include <iostream>
#include <cstdarg>

using namespace std;

template<class T>
Array<T>::Array()
{
	// Considering the default array as 1D of size 10.

	size = 10;
	dimNo = 1;
	D = new int[dimNo + 1];
	I = new int[dimNo + 1];
	D[1] = size;
	arr = new T[size];
	count = 0;	
}

template<class T>
Array<T>::Array(int d,  ...)
{
	/*
	Using va_list method to have N number of arguement. 
	D and I are created and initialized to respective values.
	*/

	va_list args;
	va_start(args, d);

	count = 0;
	size = 1;
	this->dimNo = d;
	D = new int[dimNo + 1];
	I = new int[dimNo + 1];

	for (int i = 1; i <= dimNo; i++) {
		D[i] = va_arg(args, int);
	}

	for (int i = 1; i <= dimNo; i++)
		size *= D[i];

	arr = new T[size];
	va_end(args);
}

template<class T>
int Array<T>::getIndex(int in, ...)
{
	/*
	This function converts ND indexes to 1D mapping. 
	Instead of converting index at every function, I used this function everytime passing indexes 
	as arguements.
	:param: N - indexes
	:return: Coverted linearly mapped index
	*/

	va_list args;
	va_start(args, in);

	this->I[1] = in;
	for (int i = 2; i <= dimNo; i++) {
		I[i] = va_arg(args, int);
	}

	int index = 0;
	int help = 1;
	for (int p = 1; p <= dimNo; p++) {
		help = I[p];
		for (int q = p + 1; q <= dimNo; q++) {
			help *= D[q];
		}
		index += help;
	}
	va_end(args);
	return index;
}

template<class T>
T Array<T>::at(int index)
{
	return arr[index];
}

template<class T>
void Array<T>::setValue(int index, int value)
{
	arr[index] = value;
}

template<class T>
T Array<T>::front()
{
	return arr[0];
}

template<class T>
T Array<T>::back()
{
	return arr[size - 1];
}

template<class T>
void Array<T>::resize()
{
	if (isEmpty()) {
		size = ceil(size / 2.0);
		T* arr2 = new T[size];
		for (int i = 0; i < size; i++) {
			arr2[i] = arr[i];
		}
		delete arr;
		arr = arr2;
	}
}

template<class T>
bool Array<T>::isFull()
{
	return count == size;
}

template<class T>
bool Array<T>::isEmpty()
{
	return count == 0;
}


template<class T>
Array<T>::~Array()
{
	if(arr)
		delete[] arr;
}

template<class T>
TwoD_Matrix<T>::TwoD_Matrix()
{
	/*
	On default 2 by 2 Matrix is created.
	*/

	rows = 2; 
	cols = 2;
	size = rows * cols;
	arr = new Array<T>(2, rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr->setValue(arr->getIndex(i, j), 0);
}

template<class T>
TwoD_Matrix<T>::TwoD_Matrix(int R, int C)
{
	rows = R;
	cols = C;
	size = rows * cols;
	arr = new Array<T>(2, rows,cols);

	for (int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
		arr->setValue(arr->getIndex(i,j), 0);
}


template<class T>
TwoD_Matrix<T>::TwoD_Matrix(const TwoD_Matrix& M2)
{
	rows = M2.rows;
	cols = M2.cols;
	size = rows * cols;
	arr = new Array<T>(2, rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr->setValue(arr->getIndex(i, j), 0);
}


template<class T>
int TwoD_Matrix<T>::getElement(int i, int j)
{
	return arr->at(arr->getIndex(i,j));
}

template<class T>
void TwoD_Matrix<T>::setElement(int i, int j, int val)
{
	arr->setValue(arr->getIndex(i, j), val);
}


template<class T>
void TwoD_Matrix<T>::printMatrix()
{

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr->at(arr->getIndex(i, j)) << " ";
		}
		cout << endl;
	}

}


template<class T>
void TwoD_Matrix<T>::printMatrix(const TwoD_Matrix& M2)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << M2.arr->at(M2.arr->getIndex(i, j)) << " ";
		}
		cout << endl;
	}
}


template<class T>
void TwoD_Matrix<T>::transpose()
{
	/*
	Taking transpose of the matrix and displaying it. 
	*/

	TwoD_Matrix temp1(cols, rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			temp1.setElement(j, i, arr->at(arr->getIndex(i, j)));
		}
	}
	temp1.printMatrix();
}


template<class T>
void TwoD_Matrix<T>::printSubMatrix(int r1, int r2, int c1, int c2)
{
	/*
	r1 is the starting row, r2 is the ending row.
	c1 is the starting column, c2 is the ending col.
	*/

	if (r1 >= 0 && r2 < rows && c1 >= 0 && c2 < cols) {
		for (int i = r1; i <= r2; i++) {
			for (int j = c1; j <= c2; j++) {
				cout << arr->at(arr->getIndex(i, j)) << " ";
			}
			cout << endl;
		}
	}
}


template<class T>
void TwoD_Matrix<T>::operator + (TwoD_Matrix& M2)
{
	/*
		Two matrices are added and their sum is printed on spot.
	*/

	if (rows == M2.rows && cols == M2.cols) {
		TwoD_Matrix Add(rows,cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				Add.setElement(i, j, (getElement(i, j) + M2.getElement(i, j)));
			}
		}
		Add.printMatrix();
	}
}


template<class T>
void TwoD_Matrix<T>::clear(int n)
{

	/*
	n number of rows and cols are cleared ( 0 is placed )
	*/

	if (n <= rows && n <= cols) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < cols; j++) {
				arr->setValue(arr->getIndex(i, j), 0);
			}
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < n; j++) {
				arr->setValue(arr->getIndex(i, j), 0);
			}
		}
	}
}


template<class T>
TwoD_Matrix<T>::~TwoD_Matrix()
{
	if(arr)
		delete arr;
}

