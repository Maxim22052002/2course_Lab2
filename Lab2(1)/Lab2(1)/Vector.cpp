#include "Vector.h"
#include <iostream>
#include <iomanip>
#include <cassert>

Vector::Vector()
{
	vector = new double [size];
}
Vector::~Vector()
{
	delete[] vector;
}
void Vector::makeVector(double** arr2D)
{
	int k = 0;
	const int rows = 5;
	const int cols = 3;
	for (int j = 0; j < cols; ++j)
	{
		for (int i = 0; i < rows; ++i)
		{
			*(vector+k) = *(*(arr2D + i) + j);
			k++;
		}
	}
}
void Vector::printVector()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << *(vector + i) << std::setw(10);
	}
	std::cout << std::endl;
}
double& Vector::operator[] (const int index)
{
	assert(index >= 0 && index < size);
	return *(vector + index);
}
void Vector::operator++()
{
	for (int i = 0; i < size; i++)
	{
		++* (vector + i);
	}
}
void Vector::operator++(int)
{
	for (int i = 0; i < size; i++)
	{
		(* (vector + i))++;
	}
}
void Vector::operator--()
{
	for (int i = 0; i < size; i++)
	{
		--* (vector + i);
	}
}
void Vector::operator--(int)
{
	for (int i = 0; i < size; i++)
	{
		(* (vector + i))--;
	}
}


