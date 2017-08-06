#pragma once
#include <cstring>
class Array {
public:
	Array();
	~Array();
	void push(int, int);
	int get(int);
	int pop(int);
	bool isEmpty();
	int getSize();
	int isSorted();
	int find(int);
	void sort(bool);
	void swap(int, int);
private:
	int* array;
	int size;
	int realSize;
	void reAlloc();	
	void sortDecr();
};