//BSEF19M003
//LAIBA KAMAL
#pragma once
#include<iostream>
#include<cstddef>
using namespace std;

///forward declaration of template class DLL
template<class T>
class XorDLL;

template <class T>
class XorNode
{
public:
	T data;
	XorNode<T>* npx;
	XorNode();
	XorNode(T d, XorNode<T>* ptr = NULL);
	XorNode<T>* XOR(XorNode* a, XorNode* b);
	template <class T> friend class XorDLL;
};

//BSEF19M003
//LAIBA KAMAL

