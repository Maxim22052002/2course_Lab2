// Lab2(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include"Fraction.h"
#include <iostream>
#include<string>
#include <conio.h>



//Федоров Максим, ИВТ-3, Вариант 9

/*Написать класс Fraction для представления обыкновенных дробей(как отношения
	двух целых чисел x / y).Перегрузить операторы + , -, *, / для дробей.Реализовать метод
	void reduce() для сокращения дроби, а также статические методы :
 int gcd(int n, int m)
функция для нахождения наибольшего общего делителя чисел n и m;
 void printAsFraction(double decimal_fraction)
 void printAsFraction(char* decimal_fraction)
перегруженные методы вывода десятичной дроби в виде обыкновенной
(например, при значении decimal_fraction = 0.43 на экране должно
	вывестись 43 / 100, при 0.25 – 1 / 4 и т.д.).
	Также реализовать в виде статического члена класса счетчик всех созданных на
	данный момент в программе экземпляров дробей.
	Продемонстрировать работу созданного класса.Создать несколько объектов дробей.
	Произвести операции сложения, вычитания, умножения и деления дробей.Вывести
	на экран результаты.Показать также результаты работы статических методов класса.*/



int main()
{
	setlocale(LC_ALL, "Rus");
	int nominator1 = 0;
	int nominator2 = 0;
	int denominator1 = 0;
	int denominator2 = 0;
	std::cout << "Введите числитель первой дроби:  " << std::endl;
	std::cin >> nominator1;
	std::cout << "Введите знаменатель первой дроби:  " << std::endl;
	std::cin >> denominator1;
	std::cout << "Введите числитель второй дроби:  " << std::endl;
	std::cin >> nominator2;
	std::cout << "Введите знаменатель второй дроби:  " << std::endl;
	std::cin >> denominator2;
	Fraction fract1(nominator1,denominator1);
	Fraction fract2(nominator2, denominator2);
	Fraction result;
	system("cls");
	bool errorFlag = true;
	do
	{
		std::cout << "Первая дробь:  ";
		fract1.printFraction();
		std::cout << "Вторая дробь:  ";
		fract2.printFraction();
		int n;
		std::cout << "Выберите действие:  " << std::endl;
		std::cout << "1.Нахождение НОД " << std::endl;
		std::cout << "2.Вывод десятичной дроби в виде обыкновенной" << std::endl;
		std::cout << "3.Сокращение дроби" << std::endl;
		std::cout << "4.Сложение дробей" << std::endl;
		std::cout << "5.Вычитание дробей" << std::endl;
		std::cout << "6.Умножение дробей" << std::endl;
		std::cout << "7.Деление дробей" << std::endl;
		std::cout << "8.Количество объектов класса: " << std::endl;
		std::cout << "9.Выход" << std::endl;

		char fractChar[10];
		double fractNum = 0;
		std::cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			int n, m;
			std::cout << "Введите число n: " << std::endl;
			std::cin >> n;
			std::cout << "Введите число m: " << std::endl;
			std::cin >> m;
			std::cout << "НОД: " << Fraction::gcd(n, m) << std::endl;
			_getch();
			system("cls");
			break;
			
		case 2:
			system("cls");
			std::cout << "Введите десятичную дробь для преобразования: ( через точку )(1 способ) " << std::endl;
			std::cin >> fractChar;
			Fraction::printAsFraction(fractChar);
			std::cout << "Введите десятичную дробь для преобразования: ( через точку )(2 способ) " << std::endl;
			std::cin >> fractNum;
			Fraction::printAsFraction(fractNum);
			_getch();
			system("cls");
			break;
		case 3:
			system("cls");
			fract1.reduce();
			fract2.reduce();
			fract1.printFraction();
			fract2.printFraction();
			_getch();
			system("cls");
			break;
		case 4:
			
			system("cls");
		    result = fract1 + fract2;
			result.reduce();
			result.printFraction();
			_getch();
			system("cls");
			break;
		case 5:
			
			system("cls");
			result = fract1 - fract2;
			result.reduce();
			result.printFraction();
			_getch();
			system("cls");
			break;
		case 6:
			system("cls");
			result = fract1 * fract2;
			result.reduce();
			result.printFraction();
			_getch();
			system("cls");
			break;
			break;
		case 7:
			
			system("cls");
			result = fract1 / fract2;
			result.reduce();
			result.printFraction();
			_getch();
			system("cls");
			break;
		case 8:
			system("cls");
			std::cout << "8.Количество объектов класса: ";
			std::cout << Fraction::count << std::endl;
			_getch();
			system("cls");
			break;
		case 9:
			errorFlag = false;
			break;
		default:
			std::cout << "Введите верную операцию" << std::endl;
			errorFlag = true;
			break;
		}
	} while (errorFlag);
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
