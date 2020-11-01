#include "Plane.h"

#include <conio.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
Plane::Plane() {
	model_ = "";
	airLines_ = "";
	year_ = NULL;
	capacity_ = NULL;
}
Plane::Plane(std::string model, std::string airLines, int year, int capacity) {
	model_ = model;
	airLines_ = airLines;
	year_ = year;
	capacity_ = capacity;
}
Plane::~Plane() {
}
float Plane::getPercent() {
	return (numOfPassengers_ * 1.0 / capacity_) * 100.0;
}
void Plane::setModel(std::string model) {
	model_ = model;
}
void Plane::setAirLines(std::string airLines) {
	airLines_ = airLines;
}
void Plane::setAverageValue(float value) {
	averageValue = value;
}
float Plane::getAverageValue() {
	return averageValue;
}
void Plane::setСapacity(int capacity) {
	capacity_ = capacity;
}

void Plane::setYear(int year) {
	year_ = year;
}


void Plane::Imitation()
{
	cout << "\nСамолет: " << model_ << endl;
	cout << "Вместимость: " << capacity_ << endl;
	cout << "Количество пассажиров: " << numOfPassengers_<< endl;
}
void Plane::printInfo() {
	std::cout << "Модель самолета: " << model_ << std::endl;
	std::cout << "Авиалиния: " << airLines_ << std::endl;
	std::cout << "Год выпуска: " << year_ << std::endl;
	std::cout << "Вместимость: " << capacity_ << std::endl;
	std::cout << "Средний процент заполнения самолета пассажирами: " << averageValue << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
}
void::Plane::setNumOfPassengers(int numOfPassengers) {
	numOfPassengers_ = numOfPassengers;
}
void Plane::serialize(std::string filename) {
	std::ofstream fout(filename);
	fout << model_ << std::endl;
	fout << airLines_ << std::endl;
	fout << year_ << std::endl;
	fout << capacity_ << std::endl;
	fout << averageValue << std::endl;
	fout << "-------------------------------------------------------" << std::endl;
	fout.close();
}
void Plane::serialize() {
	std::ofstream fout;
	fout.open("file.txt");
	fout << model_ << std::endl;
	fout << airLines_ << std::endl;
	fout << year_ << std::endl;
	fout << capacity_ << std::endl;
	fout << averageValue << std::endl;
	fout << "-------------------------------------------------------" << std::endl;
	fout.close();
}
void Plane::deserialize(std::string filename) {
	std::ifstream fin(filename);
	char pl1[100];
	char pl2[100];
	int pl3;
	int pl4;
	fin.getline(pl1, 100);
	model_ = pl1;
	fin.getline(pl2, 100);
	airLines_ = pl2;
	fin >> pl3;
	year_ = pl3;
	fin >> pl4;
	capacity_ = pl4;
	fin.close();
}
void Plane::deserialize() {
	std::ifstream fin("file.txt");
	char pl1[50];
	char pl2[50];
	int pl3;
	int pl4;
	fin.getline(pl1, 50);
	model_ = pl1;
	fin.getline(pl2, 50);
	airLines_ = pl2;
	fin >> pl3;
	year_ = pl3;
	fin >> pl4;
	capacity_ = pl4;
	fin.close();
}