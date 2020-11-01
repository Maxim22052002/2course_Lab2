// Lab2(3).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Федоров Максим ИВТ-3, Вариант 9

/*Написать собственный класс, в соответствии с вариантом.Продемонстрировать в коде
инкапсуляцию данных, применение конструкторов без параметров и с параметрами
для инициализации данных.Класс должен содержать метод serialize() для
сохранения данных класса в файл и метод deserialize() для чтения данных класса
из файла по умолчанию в текущей директории, а также перегруженные методы
serialize(const std::string& filename) и deserialize(const std::string&
	filename) для работы с файлом с указанным в параметре именем.*/

//Вариант 9

/*Класс САМОЛЕТ.
Данные: модель, авиалинии, год выпуска, вместимость, количество пассажиров.
Создать массив из 3 самолетов и установить их данные с помощью сеттеров.Еще один
самолет создать отдельно в куче и установить его данные в конструкторе с
параметрами.В главной функции проимитировать три рейса – случайным образом
сформировать фактическое количество пассажиров и просчитать процент заполнения
каждого самолета.Вывести информацию о самолетах, отсортировав их в порядке
убывания среднего процента заполнения за три рейса.*/


#include <iostream>
#include "Plane.h"
#include <ctime>
int main()
{
	
	srand(time(NULL));
	setlocale(0, "Rus");	
	Plane* plane = new Plane("Airbus А380", "Донецк - Ростов", 1970, 850);

	Plane planes[3] = { Plane(),Plane(),Plane() };
	planes[0].setModel("Fokker 100");
	planes[0].setAirLines("Санкт-Петербург - Москва");
	planes[0].setYear(1985);
	planes[0].setСapacity(500);
	
	planes[1].setModel("ATR 42-320");
	planes[1].setAirLines("<Белгород - Красноярск");
	planes[1].setYear(1970);
	planes[1].setСapacity(610);

	planes[2].setModel("Boeing 737 MAX");
	planes[2].setAirLines("Саратов - Смоленск");
	planes[2].setYear(1999);
	planes[2].setСapacity(550);

	float plane1_percents[3];
	float averages[4] = { 0 };
	for (int i = 0; i < 3; i++) {
		int randNumPas = (RAND_MAX - rand()) % 500;
		planes[0].setNumOfPassengers(randNumPas);
		plane1_percents[i] = planes[0].getPercent();
		averages[0] += plane1_percents[i];
	}
	planes[0].setAverageValue(averages[0] / 3);
	float plane2_percents[3];
	for (int i = 0; i < 3; i++) {
		int randNumPass = (RAND_MAX - rand()) % 610;
		planes[1].setNumOfPassengers(randNumPass);
		plane2_percents[i] = planes[1].getPercent();
		averages[1] += plane2_percents[i];
	}
	planes[1].setAverageValue(averages[1] / 3);
	float plane3_percents[3];
	for (int i = 0; i < 3; i++) {
		int randNumPass = (RAND_MAX - rand()) % 550;
		planes[2].setNumOfPassengers(randNumPass);
		plane3_percents[i] = planes[2].getPercent();
		averages[2] += plane3_percents[i];
	}
	planes[2].setAverageValue(averages[2] / 3);
	float plane4_percents[3];
	for (int i = 0; i < 3; i++) {
		int randNumPass = (RAND_MAX - rand()) % 850;
		plane->setNumOfPassengers(randNumPass);
		plane4_percents[i] = plane->getPercent();
		averages[3] += plane4_percents[i];
		//plane->Imitation();
	}
	plane->setAverageValue(averages[3] / 3);
	
	Plane allPlanes[4];
	allPlanes[0] = planes[0];
	allPlanes[1] = planes[1];
	allPlanes[2] = planes[2];
	allPlanes[3] = *plane;
	Plane::Sort(allPlanes);
	plane->serialize("file.txt");
	
	delete plane;
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
