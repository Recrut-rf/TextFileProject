#include "MainWindow.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void MainWindow::show()
{
	// ��� ����� � ������ ���������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Audience> audienceCollection{};
	string fileName = "Test.txt";
	int menuItem = 0;
	int number = 0;

	workWithAudience.readDataFromFile(audienceCollection, fileName);

	while (true)
	{
		system("cls"); // ������� ������� 
		cout << "1. ���������� ����� ������." << endl;
		cout << "2. �������������� ������ � ��������� �������." << endl;
		cout << "3. �������� ������ � ��������� �������." << endl;
		cout << "4. ����� �� ������ ���������." << endl;
		cout << "5. ����� ��������� � �������� ��������������." << endl;
		cout << "6. ����� ���������� �� �����: ��� ���������� ����� ������ ��������� � ������� ��������." << endl;
		cout << "7. �����." << endl;
		cout << "�������� ����� ����: ";
		cin >> menuItem;

		if (menuItem == 1)
		{
			workWithAudience.setNewAudience(audienceCollection);
			workWithAudience.writeFile(audienceCollection, fileName);
			system("pause");
		}
		else if (menuItem == 2)
		{
			cout << "������� ����� ��� ��������������:" << endl;
			cin >> number;
			workWithAudience.editingAudience(audienceCollection, number);
			workWithAudience.writeFile(audienceCollection, fileName);
			system("pause");
		}
		else if (menuItem == 3)
		{
			cout << "������� ����� ��� ��������:" << endl;
			cin >> number;
			workWithAudience.deleteAudience(audienceCollection, number);
			workWithAudience.writeFile(audienceCollection, fileName);
			workWithAudience.writeFile(audienceCollection, fileName);
			system("pause");
		}
		else if (menuItem == 4)
		{
			cout << "������� ����� ��� ������ ���������:" << endl;
			cin >> number;
			workWithAudience.searchByAudienceNumber(audienceCollection, number);
			system("pause");
		}
		else if (menuItem == 5)
		{
			string specialization = "";
			cout << "������� ������������� ��� ������:" << endl;
			cin >> specialization;
			workWithAudience.findingAudienceWithSpecialty(audienceCollection, specialization);
			system("pause");
		}
		else if (menuItem == 6)
		{
			cout << "������� ����� �����" << endl;
			cin >> number;
			workWithAudience.showAudienceInfo(audienceCollection, number);
			system("pause");
		}
		else if (menuItem == 7)
		{
			cout << "���������� �� ������." << endl;
			system("pause");
			break;
		}
	}
}
