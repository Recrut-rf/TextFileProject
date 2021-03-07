#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Audience.h"

using std::string;
using std::vector;

class WorkWithAudience
{
public:
	WorkWithAudience();

	// добавление новой записи
	void setNewAudience(vector<Audience> &collect);

	// редактирование записи с указанным номером
	void editingAudience(vector<Audience> &collect, int number);

	// удаление записи с указанным номером
	void deleteAudience(vector<Audience> &collect, int number);

	// поиск по номеру аудитории
	void searchByAudienceNumber(const vector<Audience> &collect, int roomNumber);

	// поиск аудитории с заданной специализацией
	void findingAudienceWithSpecialty(const vector<Audience> &collect, string specialization);

	// Вывод информации на экран: для указанного этажа список аудиторий в порядке возрастания
	void showAudienceInfo(const vector<Audience> &audienceintsCollection, int floor);

	// запись данных в файл
	void writeFile(const vector<Audience> &collect, string fileName);

	// чтение данных из файла
	void readDataFromFile(vector<Audience> &collect, string fileName);

};

