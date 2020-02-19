#include "stdio.h"
void changeByValue(int, int);
void changeByPointer(int*, int*);
void changeByReference(int&, int&);
void main()
{
	int a = 7;
	int b = 9;
	printf("Before: a=%d, b=%d \n", a, b);
	//changeByValue(a, b);
	//changeByPointer(&a, &b);
	changeByReference(a, b);
	printf("After:  a=%d, b=%d \n", a, b);
}
void changeByReference(int& x, int& y)
{
	int aux = x;
	x = y;
	y = aux;
}

void changeByPointer(int* x, int* y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

void changeByValue(int x, int y)
{
	int aux = x;
	x = y;
	y = aux;
}