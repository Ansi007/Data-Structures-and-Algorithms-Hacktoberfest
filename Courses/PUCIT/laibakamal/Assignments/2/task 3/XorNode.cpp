

//BSEF19M003
//LAIBA KAMAL
#include "XorNode.h"
template<class T>
XorNode<T>::XorNode()//default constructor
{
	this->data = 0;
	this->npx = NULL;
}
template<class T>
XorNode<T>::XorNode(T data, XorNode<T>* ptr)// parameterized constructorl
{
	this->data = data;
	this->npx = ptr;
}
template<class T>
XorNode<T>* XorNode<T>::XOR(XorNode<T>* a, XorNode<T>* b)
{
	npx = reinterpret_cast<XorNode<T>*>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
	return npx;
}
//BSEF19M003
//LAIBA KAMAL


