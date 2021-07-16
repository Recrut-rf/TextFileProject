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
	
	void setNewAudience(vector<Audience> &collect);
	
	void editingAudience(vector<Audience> &collect, int number);
	
	void deleteAudience(vector<Audience> &collect, int number);
	
	void searchByAudienceNumber(const vector<Audience> &collect, int roomNumber);
	
	void findingAudienceWithSpecialty(const vector<Audience> &collect, string specialization);
	
	void showAudienceInfo(const vector<Audience> &audienceintsCollection, int floor);
	
	void writeFile(const vector<Audience> &collect, string fileName);
	
	void readDataFromFile(vector<Audience> &collect, string fileName);
};

