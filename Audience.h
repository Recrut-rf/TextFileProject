#pragma once
#include <fstream>
#include <string>


class Audience
{
public:
	Audience() = default; 
	
	Audience(std::string _specialization) : specialization(_specialization)
	{	}

	Audience(int  _roomNumber) : roomNumber(_roomNumber)
	{	}
	
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
	
	std::ostream& printAudience(std::ostream& ostr) const; 															
	std::istream& scanAudience(std::istream& ostr); 
													  
	bool operator== (int number) const;
	bool operator== (std::string specialization) const;

private:	
	std::string specialization{}; 
	int roomNumber{};        
	int floor{};             
	int numberOfSeats{};     
	int classroomArea{};     
};
