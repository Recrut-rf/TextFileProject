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


//---------------------------Предикат------------------
bool audienceGreater(Audience &lhs, Audience &rhs)
{
	return lhs.getRoomNumber() > rhs.getRoomNumber();
}

// перегрузим оператор ввода (>>) 
istream& operator >> (istream &istrm, Audience &rhs)
{
	return rhs.scanAudience(istrm);
}

// перегрузим оператор вывода (<<)
ostream& operator<< (ostream &istrm, const Audience &rhs)
{
	return rhs.printAudience(istrm);
}

WorkWithAudience::WorkWithAudience(/*Audience _audience) : audience(_audience*/)
{   }

void WorkWithAudience::setNewAudience(vector<Audience>& collect)
{
	Audience temp;
	string specialization{}; // специализация
	int roomNumber{};        // номер аудитории 
	int floor{};             // этаж
	int numberOfSeats{};     // число посадочных мест
	int classroomArea{};     // площадь аудитории

	cout << "Введите специализацию (одним слововом без пробелов):" << endl;
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
		cout << "Введите новые параметры аудитории: \n";
		cout << "специализация:\n";
		cin >> tempSpecialization;
		result->setSpecialization(tempSpecialization);
		cout << "этаж:\n";
		cin >> tempFloor;
		result->setFloor(tempFloor);
		cout << "число мест:\n";
		cin >> tempNumberOfSeats;
		result->setNumberOfSeats(tempNumberOfSeats);
		cout << "площадь:\n";
		cin >> tempClassroomArea;
		result->setClassroomArea(tempClassroomArea);
	}
	else
		cout << "Аудитория с номером: " << number << " не найдена\n";
}

void WorkWithAudience::deleteAudience(vector<Audience>& collect, int number)
{
	auto result = find(collect.begin(), collect.end(), number);

	if (result != collect.end())
	{
		*result = std::move(collect.back());
		collect.pop_back();
		cout << "Аудитория с номером: " << number << " удалена\n";
	}
	else
		cout << "Аудитория с номером: " << number << " не найдена\n";
}

void WorkWithAudience::searchByAudienceNumber(const vector<Audience>& audienceintsCollection, int roomNumber)
{
	auto result = find(audienceintsCollection.begin(), audienceintsCollection.end(), roomNumber);

	if (result != audienceintsCollection.end())
		cout << "Аудитория с номером: " << roomNumber << " найдена\n";
	else
		cout << "Аудитория с номером: " << roomNumber << " не найдена\n";
}

void WorkWithAudience::findingAudienceWithSpecialty(const vector<Audience>& collect, string specialization)
{
	auto result = find(collect.begin(), collect.end(), specialization);

	if (result != collect.end())
		cout << "Аудитория со специализацией: " << specialization << " найдена\n";
	else
		cout << "Аудитория со специализацией: " << specialization << " не найдена\n";
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
		cout << "Аудиторий для этажа " << floor << " не найдено\n";
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

	// получаем данные из файла
	if (!file.is_open())
	{
		cout << "Не удалось открыть файл будут созданы новые записи\n";
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
