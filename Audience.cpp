#include "Audience.h"

std::ostream & Audience::printAudience(std::ostream & ostr) const
{
	// для записи вида: 100,100,100,специализация	
	return ostr << roomNumber << ','
		<< floor << ','
		<< numberOfSeats << ','
		<< classroomArea << ','
		<< specialization << '\n';
}

std::istream & Audience::scanAudience(std::istream & ostr)
{
	// актуально для файла, в котором данные разделены ','
	// например для данных вида: 100,100,100,специализация
	ostr >> roomNumber;
	ostr.ignore();      // пропускаем символ запятой из файла 
	ostr >> floor;
	ostr.ignore();      // пропускаем символ запятой из файла
	ostr >> numberOfSeats;
	ostr.ignore();      // пропускаем символ запятой из файла 
	ostr >> classroomArea;
	ostr.ignore();      // пропускаем символ запятой из файла
	ostr >> specialization;
	return ostr;
}

bool Audience::operator==(int number) const
{
	return this->getRoomNumber() == number;
}

bool Audience::operator==(std::string specialization) const
{
	return this->getSpecialization() == specialization;
}

void Audience::setSpecialization(std::string _specialization)
{
	specialization = _specialization;
}

void Audience::setRoomNumber(int _roomNumber)
{
	roomNumber = _roomNumber;
}

void Audience::setFloor(int _floor)
{
	floor = _floor;
}

void Audience::setNumberOfSeats(int _numberOfSeats)
{
	numberOfSeats = _numberOfSeats;
}

void Audience::setClassroomArea(int _classroomArea)
{
	classroomArea = _classroomArea;
}

std::string Audience::getSpecialization() const
{
	return specialization;
}

int Audience::getRoomNumber() const
{
	return roomNumber;
}

int Audience::getFloor() const
{
	return floor;
}

int Audience::getNumberOfSeats() const
{
	return numberOfSeats;
}

int Audience::getClassroomArea() const
{
	return classroomArea;
}

