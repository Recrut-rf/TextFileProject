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
	// для ввода и вывода кириллицы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Audience> audienceCollection{};
	string fileName = "Test.txt";
	int menuItem = 0;
	int number = 0;

	workWithAudience.readDataFromFile(audienceCollection, fileName);

	while (true)
	{
		system("cls"); // очистка консоли 
		cout << "1. Добавление новой записи." << endl;
		cout << "2. Редактирование записи с указанным номером." << endl;
		cout << "3. Удаление записи с указанным номером." << endl;
		cout << "4. Поиск по номеру аудитории." << endl;
		cout << "5. Поиск аудитории с заданной специализацией." << endl;
		cout << "6. Вывод информации на экран: для указанного этажа список аудиторий в порядке убывания." << endl;
		cout << "7. Выход." << endl;
		cout << "Выберете пункт меню: ";
		cin >> menuItem;

		if (menuItem == 1)
		{
			workWithAudience.setNewAudience(audienceCollection);
			workWithAudience.writeFile(audienceCollection, fileName);
			system("pause");
		}
		else if (menuItem == 2)
		{
			cout << "Введите номер для редактирования:" << endl;
			cin >> number;
			workWithAudience.editingAudience(audienceCollection, number);
			workWithAudience.writeFile(audienceCollection, fileName);
			system("pause");
		}
		else if (menuItem == 3)
		{
			cout << "Введите номер для удаления:" << endl;
			cin >> number;
			workWithAudience.deleteAudience(audienceCollection, number);
			workWithAudience.writeFile(audienceCollection, fileName);
			workWithAudience.writeFile(audienceCollection, fileName);
			system("pause");
		}
		else if (menuItem == 4)
		{
			cout << "Введите номер для поиска аудитории:" << endl;
			cin >> number;
			workWithAudience.searchByAudienceNumber(audienceCollection, number);
			system("pause");
		}
		else if (menuItem == 5)
		{
			string specialization = "";
			cout << "Введите специализацию для поиска:" << endl;
			cin >> specialization;
			workWithAudience.findingAudienceWithSpecialty(audienceCollection, specialization);
			system("pause");
		}
		else if (menuItem == 6)
		{
			cout << "Введите номер этажа" << endl;
			cin >> number;
			workWithAudience.showAudienceInfo(audienceCollection, number);
			system("pause");
		}
		else if (menuItem == 7)
		{
			cout << "Благодарим за работу." << endl;
			system("pause");
			break;
		}
	}
}
