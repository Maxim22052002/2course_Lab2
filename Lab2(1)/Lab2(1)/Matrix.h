#pragma once
class Matrix
{
public: Matrix();
	  ~Matrix();
	  double at(int i, int j);
	  void setAt(int i, int j, double value);
	  void printMatrix();
	  void operator++();
	  void operator++ (int);
	  void operator-- ();
	  void operator-- (int);
	  void initializeMatrix();
	  double** getMatrix();
private:
	const int rows = 5, cols = 3;
	double** matrix;

};

