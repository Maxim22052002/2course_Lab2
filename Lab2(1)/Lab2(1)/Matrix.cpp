#include "Matrix.h"
#include <iostream>
#include <iomanip>

Matrix::Matrix()
{
	matrix = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		*(matrix + i) = new double[cols];
	}
}
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] * (matrix + i);
	}
	delete[] matrix;
}
void Matrix::printMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << std::setw(10) << *(*(matrix + i) + j);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void Matrix::initializeMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*(*(matrix + i) + j) = sin(i - j) + cos(i + j);
		}
		
	}
}
double Matrix::at(int i, int j)
{
	return *(*(matrix + i) + j);
}
void Matrix::setAt(int i, int j, double value)
{
	*(*(matrix + i) + j) = value;
}
void Matrix::operator++ ()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			++*(*(matrix + i) + j);
		}

	}
}
void Matrix::operator++ (int)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			(*(*(matrix + i) + j))++;
		}

	}
}
void Matrix::operator-- ()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			--*(*(matrix + i) + j);
		}

	}
}
void Matrix::operator-- (int)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			(*(*(matrix + i) + j))--;
		}

	}
}
double** Matrix::getMatrix()
{
	return matrix;
}
	

