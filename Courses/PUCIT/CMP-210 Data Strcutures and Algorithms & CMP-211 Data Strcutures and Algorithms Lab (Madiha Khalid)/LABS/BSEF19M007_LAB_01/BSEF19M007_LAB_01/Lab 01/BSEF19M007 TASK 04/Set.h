#pragma once
#include<iostream>

using namespace std;

class Set {
private:
	int* set, size;
public:
	void Create();
	void Insert(int);
	void Remove(int);
	bool IsMember(int);
	Set Union(Set);
	Set Intersection(Set);
	bool IsSubset(Set);
	void RemoveReppition();
	void Print();
	void Sort();
};

