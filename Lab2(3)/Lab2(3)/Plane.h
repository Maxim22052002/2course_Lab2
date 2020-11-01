#pragma once
#include <string>
class Plane
{
public:
	Plane(std::string model, std::string airLines, int year, int capacity);
	~Plane();
	Plane();
	void setModel(std::string model);
	void setAirLines(std::string airLines);
	void setYear(int year);
	void set—apacity(int capacity);
	void setNumOfPassengers(int numOfPassengers);
	
	void Imitation();
	void serialize(std::string filename);
	void deserialize(std::string filename);
	void serialize();
	void deserialize();
	void printInfo();
	void setAverageValue(float value);
	float getAverageValue();
	float getPercent();
	static void Sort(Plane planes[4]) {
		for (int i = 0; i < 4; i++) {
			int max = i;
			for (int j = i + 1; j < 4; j++) {
				if (planes[j].getAverageValue() > planes[max].getAverageValue()) {
					max = j;
				}
			}
			std::swap(planes[max], planes[i]);
		}
		for (int i = 0; i < 4; i++) {
			planes[i].printInfo();
			
		}
	}
private:
	std::string model_;
	std::string airLines_;
	int year_;
	int capacity_;
	int numOfPassengers_ = 0;
	float averageValue;
	
};

