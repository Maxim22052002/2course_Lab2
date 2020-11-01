#include "Fraction.h"
#include <string>
#include <sstream>
#include<iostream>
#include<cmath>


Fraction::Fraction()
{
	nominator_ = 0;
	denominator_ = 0;
	count++;
}

Fraction::Fraction(int nominator, int denominator) {
	if (denominator != 0) {
		nominator_ = nominator;
		denominator_ = denominator;;
		count++;
	}
	else
	{
		std::cout << "Error." << std::endl;
	}
}


Fraction::~Fraction()
{

}

Fraction Fraction::operator+ (Fraction resfract) {
	Fraction result (this->nominator_ * resfract.denominator_ + resfract.nominator_ * this->denominator_, this->denominator_ * resfract.denominator_);
	result.reduce();
	return result;
}
Fraction Fraction::operator-(Fraction resfract) {
	Fraction result (this->nominator_ * resfract.denominator_ - resfract.nominator_ * this->denominator_, this->denominator_ * resfract.denominator_);
	result .reduce();
	return result;
}
Fraction Fraction::operator* (Fraction resfract) {
	Fraction result (this->nominator_ * resfract.nominator_, this->denominator_ * resfract.denominator_);
	result.reduce();
	return result;
}
Fraction Fraction::operator/ (Fraction resfract) {
	Fraction result (this->nominator_ * resfract.denominator_, this->denominator_ * resfract.nominator_);
	result.reduce();
	return result;
}

void Fraction::reduce()
{
	int gcd1 = gcd(nominator_, denominator_);
	nominator_ = nominator_ / gcd1;
	denominator_ = denominator_ / gcd1;
}
void Fraction::printFraction() {
	if (nominator_ != 0) {
		std::cout << nominator_ << "/" << denominator_ << std::endl;
	}
	else
	{
		std::cout << 0 << std::endl;
	}
}
int Fraction::getNominator() {
	return nominator_;
}
int Fraction::getDenominator() {
	return denominator_;
}
void Fraction::setNominator(int nominator) {
	nominator_ = nominator;
}
void Fraction::setDenominator(int denominator) {
	denominator_ = denominator;
}
int Fraction::gcd(int n, int m) {
	int gcd = 1;
	while (m != 0)
	{
		gcd = m;
		m = n % m;
		n = gcd;
	}
	return gcd;
}
void Fraction::printAsFraction(double decimal_fraction)
{
	Fraction fract;
	std::string flag;
	std::string fractString = std::to_string(decimal_fraction);
	int i = 0;
	std::string denomStr;
	std::istringstream isStr(fractString);
	while (getline(isStr, flag, ','))
	{
		if (i == 1)
			denomStr = flag;
		i++;
	}
	fract.nominator_ = decimal_fraction * pow(10, denomStr.size());
	fract.denominator_ = pow(10, denomStr.size());
	fract.reduce();
	fract.printFraction();
}
void Fraction::printAsFraction(char* decimal_fraction)
{
	Fraction fract;
	std::string flag;
	int i = 0;
	int nominator, denominator;
	std::string denomStr;
	std::istringstream isStr(decimal_fraction);
	while (getline(isStr, flag, '.'))
	{
		if (i == 0) nominator = atoi(flag.c_str());
		if (i == 1)
		{
			denominator = atoi(flag.c_str());
			denomStr = flag;
		}
		i++;
	}

	fract.denominator_ = pow(10, denomStr.size());
	fract.nominator_ = fract.denominator_ * nominator + denominator;
	if (fract.denominator_ == 0)
	{
		std::cout << "Error";
		fract.nominator_, fract.denominator_ = 1;
	}
	fract.reduce();
	fract.printFraction();
}
 int Fraction::count = 0;