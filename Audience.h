#pragma once
#include <fstream>
#include <string>


class Audience
{
public:
	Audience() = default;  // конструктор без параметров
	                       // при создании объекта без параметров
			       // все его приватные члены будут
			       // инициализированы дефолтными значениями 

	Audience(std::string _specialization) : specialization(_specialization)
	{	}

	Audience(int  _roomNumber) : roomNumber(_roomNumber)
	{	}

	// для редактирования определим методы get (для получения значений)
	// и set (для установки значений) это есть одна из трех	
	std::string getSpecialization() const;
	int getRoomNumber() const;
	int getFloor() const;
	int getNumberOfSeats() const;
	int getClassroomArea() const;

	void setSpecialization(std::string _specialization);
	void setRoomNumber(int _roomNumber);
	void setFloor(int _floor);
	void setNumberOfSeats(int _numberOfSeats);
	void setClassroomArea(int _classroomArea);

	// перегрузим операторы ввода вывода для упрощения работы
	// можно сделать через дружественные функции, но самым правильным способом будет:
	// оператор вывода
	std::ostream& printAudience(std::ostream& ostr) const;  // пишем в явном виде метод вывода	

	// оператор ввода
	std::istream& scanAudience(std::istream& ostr);   // пишем в явном виде метод ввода	

	//---------------------------Перегруженные операторы равенства----------------
	bool operator== (int number) const;

	bool operator== (std::string specialization) const;

private:
	// все параметры инициализированы дефолтными значениями (для int это 0, для string "")
	// спомощью {}
	std::string specialization{}; // специализация
	int roomNumber{};             // номер аудитории 
	int floor{};                  // этаж
	int numberOfSeats{};          // число посадочных мест
	int classroomArea{};          // площадь аудитории
};

