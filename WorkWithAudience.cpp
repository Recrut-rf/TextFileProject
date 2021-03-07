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


//---------------------------��������------------------
bool audienceGreater(Audience &lhs, Audience &rhs)
{
	return lhs.getRoomNumber() > rhs.getRoomNumber();
}

// ���������� �������� ����� (>>) 
istream& operator >> (istream &istrm, Audience &rhs)
{
	return rhs.scanAudience(istrm);
}

// ���������� �������� ������ (<<)
ostream& operator<< (ostream &istrm, const Audience &rhs)
{
	return rhs.printAudience(istrm);
}

WorkWithAudience::WorkWithAudience(/*Audience _audience) : audience(_audience*/)
{   }

void WorkWithAudience::setNewAudience(vector<Audience>& collect)
{
	Audience temp;
	string specialization{}; // �������������
	int roomNumber{};        // ����� ��������� 
	int floor{};             // ����
	int numberOfSeats{};     // ����� ���������� ����
	int classroomArea{};     // ������� ���������

	cout << "������� ������������� (����� �������� ��� ��������):" << endl;
	cin >> specialization;
	temp.setSpecialization(specialization);

	cout << "������� ����� ���������:" << endl;
	cin >> roomNumber;
	temp.setRoomNumber(roomNumber);

	cout << "������� ����:" << endl;
	cin >> floor;
	temp.setFloor(floor);

	cout << "������� ����� ���������� ����:" << endl;
	cin >> numberOfSeats;
	temp.setNumberOfSeats(numberOfSeats);

	cout << "������� ������� ���������:" << endl;
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
		cout << "������� ����� ��������� ���������: \n";
		cout << "�������������:\n";
		cin >> tempSpecialization;
		result->setSpecialization(tempSpecialization);
		cout << "����:\n";
		cin >> tempFloor;
		result->setFloor(tempFloor);
		cout << "����� ����:\n";
		cin >> tempNumberOfSeats;
		result->setNumberOfSeats(tempNumberOfSeats);
		cout << "�������:\n";
		cin >> tempClassroomArea;
		result->setClassroomArea(tempClassroomArea);
	}
	else
		cout << "��������� � �������: " << number << " �� �������\n";
}

void WorkWithAudience::deleteAudience(vector<Audience>& collect, int number)
{
	auto result = find(collect.begin(), collect.end(), number);

	if (result != collect.end())
	{
		*result = std::move(collect.back());
		collect.pop_back();
		cout << "��������� � �������: " << number << " �������\n";
	}
	else
		cout << "��������� � �������: " << number << " �� �������\n";
}

void WorkWithAudience::searchByAudienceNumber(const vector<Audience>& audienceintsCollection, int roomNumber)
{
	auto result = find(audienceintsCollection.begin(), audienceintsCollection.end(), roomNumber);

	if (result != audienceintsCollection.end())
		cout << "��������� � �������: " << roomNumber << " �������\n";
	else
		cout << "��������� � �������: " << roomNumber << " �� �������\n";
}

void WorkWithAudience::findingAudienceWithSpecialty(const vector<Audience>& collect, string specialization)
{
	auto result = find(collect.begin(), collect.end(), specialization);

	if (result != collect.end())
		cout << "��������� �� ��������������: " << specialization << " �������\n";
	else
		cout << "��������� �� ��������������: " << specialization << " �� �������\n";
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
		cout << "��������� ��� ����� " << floor << " �� �������\n";
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

	// �������� ������ �� �����
	if (!file.is_open())
	{
		cout << "�� ������� ������� ���� ����� ������� ����� ������\n";
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
