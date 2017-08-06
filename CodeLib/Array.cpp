#include "Array.h"

Array::Array()
{
	realSize = 5;
	size = 0;
	array = new int[realSize];
}

Array::~Array()
{
	delete[] array;
}

void Array::push(int value, int pos = 0)
{
	if(size == realSize) {
		reAlloc();
	} 
	if(pos > size) {
		
	} else {
		size++;
		for (int i = size-1; i >= pos; i--) {
			array[i + 1] = array[i];
		}
		array[pos] = value;
	}
}

int Array::get(int pos)
{
	return array[pos];
}

int Array::pop(int pos)
{
	int a = array[pos];
	for (int i = pos + 1; i <= size; i++) {
		array[i - 1] = array[i];
	}
	size--;
}

bool Array::isEmpty()
{
	if (size == 0) return true;
	else return false;
}

int Array::getSize()
{
	return size;
}

int Array::isSorted()
{
	char sort = 'N';
	for (int i = 0; i < size - 1; i++) {
		if (array[i] > array[i + 1]) {
			if (sort = 'N') sort = 'D';
			if (sort = 'I') return 0;
		}
		if (array[i] < array[i + 1]) {
			if (sort = 'N') sort = 'I';
			if (sort = 'D') return 0;
		}
	}
	if (sort = 'D') return -1;
	if (sort = 'I') return 1;
}

int Array::find(int elem)
{
	int pos = 0;
	if (isSorted() == 1) {
		while (elem <= array[pos]) {
			if (elem == array[pos]) return pos;
			pos++;
			if (pos == size) return -1;
		}
	}
	if (isSorted() == -1) {
		while (elem >= array[pos]) {
			if (elem == array[pos]) return pos;
			pos++;
			if (pos == size) return -1;
		}
	}
	if (isSorted() == 0) {
		for (int i = 0; i < size; i++) {
			if (elem == array[i]) return i;
		}
		return -1;
	}
}

void Array::sort(bool a = false)
{
	if (a) sortDecr();
	else {
		int k = size - 1;
		for (int j = 0; j < size - 1; j++) {
			for (int i = 0; i < k; i++) {
				if (array[i] > array[i + 1]) {
					swap(i, i + 1);
					k = i;
				} 
			}
		}			
	}
	
}

void Array::sortDecr()
{
	int k = size - 1;
	for (int j = 0; j < size - 1; j++) {
		for (int i = 0; i < k; i++) {
			if (array[i] < array[i + 1]) {
				swap(i, i + 1);
				k = i;
			}
		}
	}
}

void Array::swap(int pos1, int pos2)
{
	int temp;
	temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
}

void Array::reAlloc()
{
	realSize += 5;
	int* newArray = new int[realSize];
	memcpy(newArray, array, realSize - 5);
}
