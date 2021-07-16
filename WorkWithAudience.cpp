#include "WorkWithAudience.h"
#include <fstream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;


//---------------------------Ïðåäèêàò------------------
bool audienceGreater(Audience &lhs, Audience &rhs)
{
	return lhs.getRoomNumber() > rhs.getRoomNumber();
}

istream& operator >> (istream &istrm, Audience &rhs)
{
	return rhs.scanAudience(istrm);
}

ostream& operator<< (ostream &istrm, const Audience &rhs)
{
	return rhs.printAudience(istrm);
}

WorkWithAudience::WorkWithAudience()
{   }

void WorkWithAudience::setNewAudience(vector<Audience>& collect)
{
	Audience temp;
	string specialization{}; 
	int roomNumber{};         
	int floor{};             
	int numberOfSeats{};     
	int classroomArea{};     

	cout << "Введите специализацию:" << endl;
	cin >> specialization;
	temp.setSpecialization(specialization);

	cout << "Введите номер аудитории:" << endl;
	cin >> roomNumber;
	temp.setRoomNumber(roomNumber);

	cout << "Введите этаж:" << endl;
	cin >> floor;
	temp.setFloor(floor);

	cout << "Введите число посадочных мест:" << endl;
	cin >> numberOfSeats;
	temp.setNumberOfSeats(numberOfSeats);

	cout << "Введите площадь аудитории:" << endl;
	cin >> classroomArea;
	temp.setClassroomArea(classroomArea);

	collect.push_back(temp);
}

void WorkWithAudience::editingAudience(std::vector<Audience>& collect, int number)
{
	string tempSpecialization{};
	int tempFloor{};
	int tempNumberOfSeats{};
	int tempClassroomArea{};

	auto result = find(collect.begin(), collect.end(), number);

	if (result != collect.end())
	{
		cout << "Введите специализацию для поиска: \n";
		cout << "ñïåöèàëèçàöèÿ:\n";
		cin >> tempSpecialization;
		result->setSpecialization(tempSpecialization);
		cout << "ýòàæ:\n";
		cin >> tempFloor;
		result->setFloor(tempFloor);
		cout << "÷èñëî ìåñò:\n";
		cin >> tempNumberOfSeats;
		result->setNumberOfSeats(tempNumberOfSeats);
		cout << "ïëîùàäü:\n";
		cin >> tempClassroomArea;
		result->setClassroomArea(tempClassroomArea);
	}
	else
		cout << "Àóäèòîðèÿ ñ íîìåðîì: " << number << " íå íàéäåíà\n";
}

void WorkWithAudience::deleteAudience(vector<Audience>& collect, int number)
{
	auto result = find(collect.begin(), collect.end(), number);

	if (result != collect.end())
	{
		*result = std::move(collect.back());
		collect.pop_back();
		cout << "Àóäèòîðèÿ ñ íîìåðîì: " << number << " óäàëåíà\n";
	}
	else
		cout << "Àóäèòîðèÿ ñ íîìåðîì: " << number << " íå íàéäåíà\n";
}

void WorkWithAudience::searchByAudienceNumber(const vector<Audience>& audienceintsCollection, int roomNumber)
{
	auto result = find(audienceintsCollection.begin(), audienceintsCollection.end(), roomNumber);

	if (result != audienceintsCollection.end())
		cout << "Àóäèòîðèÿ ñ íîìåðîì: " << roomNumber << " íàéäåíà\n";
	else
		cout << "Àóäèòîðèÿ ñ íîìåðîì: " << roomNumber << " íå íàéäåíà\n";
}

void WorkWithAudience::findingAudienceWithSpecialty(const vector<Audience>& collect, string specialization)
{
	auto result = find(collect.begin(), collect.end(), specialization);

	if (result != collect.end())
		cout << "Àóäèòîðèÿ ñî ñïåöèàëèçàöèåé: " << specialization << " íàéäåíà\n";
	else
		cout << "Àóäèòîðèÿ ñî ñïåöèàëèçàöèåé: " << specialization << " íå íàéäåíà\n";
}

void WorkWithAudience::showAudienceInfo(const vector<Audience>& collect, int floor)
{
	vector<Audience> tempAudienceColl{};

	size_t size = collect.size();
	for (size_t i = 0; i < size; ++i)
	{
		if (collect[i].getFloor() == floor)
			tempAudienceColl.push_back(collect[i]);
	}

	size_t tempAudienceCollSize = tempAudienceColl.size();
	if (tempAudienceCollSize > 0)
		std::sort(tempAudienceColl.begin(), tempAudienceColl.end(), audienceGreater);
	else
	{
		cout << "Àóäèòîðèé äëÿ ýòàæà " << floor << " íå íàéäåíî\n";
		return;
	}

	for (size_t i = 0; i < tempAudienceCollSize; ++i)
	{
		cout << tempAudienceColl[i] << endl;
	}
}

void WorkWithAudience::writeFile(const vector<Audience>& collect, string fileName)
{
	ofstream writeFile(fileName);

	for (size_t i = 0; i < collect.size(); ++i)
		writeFile << collect[i];

	writeFile.close();
}

void WorkWithAudience::readDataFromFile(vector<Audience>& collect, string fileName)
{
	ifstream file(fileName);

	// ïîëó÷àåì äàííûå èç ôàéëà
	if (!file.is_open())
	{
		cout << "Íå óäàëîñü îòêðûòü ôàéë áóäóò ñîçäàíû íîâûå çàïèñè\n";
		return;
	}
	else
	{
		while (true)
		{
			Audience temp;
			if (!(file >> temp))
				break;
			else
				collect.push_back(temp);
		}
	}
	file.close();
}
