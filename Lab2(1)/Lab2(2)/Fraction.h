#pragma once
#include <string>

class Fraction
{
public:
	Fraction();
	~Fraction();
	Fraction(int nominator, int denominator);
	Fraction operator+ (Fraction f);
	Fraction operator- (Fraction f);
	Fraction operator* (Fraction f);
	Fraction operator/ (Fraction f);

	void reduce();
	void printFraction();
	void setNominator(int nominator);
	void setDenominator(int denominator);
	int getNominator();
	int getDenominator();
	static int gcd(int n, int m);
	static void printAsFraction(double decimal_fraction);
	static void printAsFraction(char* decimal_fraction);
    static int count;
private:
	int nominator_;
	int denominator_;
	
};

