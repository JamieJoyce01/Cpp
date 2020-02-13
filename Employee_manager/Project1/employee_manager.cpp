#include "employee_manager.h"
#include <fstream>
#include <string>
#include <iostream>
#include <ctype.h>
#include <iomanip>

using namespace std;
void employeemanager::initfile(array<employee*, max_employees> &listt)
{
	employee Temp;
	int x = 0;
	int y = 0;
	int i = 0;
	std::string line[max_employees];
	std::ifstream file("Employeest.csv");
	if (file.is_open())
	{
		while (std::getline(file, line[i]))
		{
			listt[i] = new employee;
			listt[i]->name = line[i].substr(0, line[i].find(","));
			line[i].erase(0, line[i].find(",") + 1);
			listt[i].address = line[i].substr(0, line[i].find(","));
			line[i].erase(0, line[i].find(",") + 1);
			listt[i].phone[0] = line[i].substr(0, line[i].find(","));
			line[i].erase(0, line[i].find(",") + 1);
			listt[i].phone[1] = line[i].substr(0, line[i].find(","));
			line[i].erase(0, line[i].find(",") + 1);
			listt[i].DoB = line[i].substr(0, line[i].find(","));
			line[i].erase(0, line[i].find(",") + 1);
			listt[i].Employment = line[i].substr(0, line[i].find(","));
			line[i].erase(0, line[i].find(",") + 1);

			i++;
		}
		file.close();
	}
}
void employeemanager::saveemployee(array<employee, max_employees> &listt) {
	std::fstream File;
	File.open("Employeest.csv", std::ios::out | std::ios::trunc);
	if (File.is_open()) {
		for (auto i : listt) {
			if (i.name == "") { break; };
			File << i.name << "," << i.address << "," << i.phone[0] << "," << i.phone[1] << "," << i.DoB << "," << i.Employment << "\n";
		}
		File.close();
	}
}

void employeemanager::newemployee(array<employee, max_employees> &listt) {
	int i = 0;
	while (listt[i].name != "") { i++; }
	if (i >= max_employees) { return; }
	std::cout << "---Add Employee---\nFull Name: ";
	std::getline(std::cin, listt[i].name);
	std::cin.clear();
	std::cout << "\nRole: ";
	std::cin >> listt[i].Employment;
	std::cin.ignore();
	std::cout << "\nAddress: ";
	std::getline(std::cin, listt[i].address);
	std::cin.clear();
	std::cout << "\nMobile Number: ";
	std::cin >> listt[i].phone[0];
	std::cout << "\nHome Number: ";
	std::cin >> listt[i].phone[1];
	std::cout << "\nDate of Birth (DD/MM/YYYY): ";
	std::cin >> listt[i].DoB;

	std::string UEN = char(toupper(listt[i].name[0]))+(listt[i].DoB.substr(0,2)) + (listt[i].DoB.substr(9,1)) + (listt[i].DoB.substr(8, 1)) + (listt[i].DoB.substr(3, 2));
	cout << UEN;
}

void employeemanager::viewemployees(array<employee, max_employees> &listt)
{
	cout << setw(20) << left << "\nFull Name" << setw(25) << " Role" << setw(25) << " Address" << setw(15) << " Mobile Phone" << setw(15) << " Home Phone" << setw(15) << " Date of Birth\n\n";
	for (auto i : listt) {
		if (i.name == "") { break; };
		cout << setw(20) << left << i.name << setw(25) << i.Employment << setw(25) << i.address << setw(15) << i.phone[0] << setw(15) << i.phone[1] << setw(15) << i.DoB << "\n";
	}
}


float employee::increase_salary(float x)
{
	return x += 0.50f;
}
/*
void bookmanager::searchbook(book listt[]) {
	std::cout << "Please enter the title of the book you would like to seach \n>>> ";
	std::string temp;
	std::getline(std::cin, temp);
	std::cin.ignore();
	for (int i = 0; i < max_books; i++)
	{
		if (temp == listt[i].title)
		{
			std::cout << "Title: " << listt[i].title << "\nAuthor: " << listt[i].author << "\nNumber Available: " << listt[i].noA << "\nTotal Number Owned: " << listt[i].noO;
		}
	}
}

void bookmanager::addbook(book listt[]) {
	std::string title;
	std::string author;
	int noA;
	int noO;
	std::cout << "---Add Book---\nTitle: ";
	std::getline(std::cin, title);
	std::cin.clear();
	std::cout << "\nAuthor: ";
	std::cin >> author;
	std::cout << "\nNumber Available: ";
	std::cin >> noA;
	std::cout << "\nNumber in total: ";
	std::cin >> noO;
	std::cout << sizeof(listt) / sizeof(listt[0]);

}

void bookmanager::delbook(book listt[]) {
	/*
	std::cout << "Please enter the title of the book you would like to delete \n>>> ";
	std::string temp;
	std::cin >> temp;
	for (int i = 0; i < max_books; i++)
	{
	if (temp == listt[i].title)
	{

	}
	} 
}
*/