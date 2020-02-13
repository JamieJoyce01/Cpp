#include <iostream>
#include <fstream>
#include <array>
#include "employee_manager.h"
using namespace std;


class Manager :public employee {
public:
	string rn = "Manager";
	float salary_promo(float x) {
		return x += 2.0f;
	}
};
class Amanager :public employee {
public:
	string rn = "Assistant Manager";
	float salary_promo(float x) {
		return x += 1.50f;
	}
};

class Techman :public employee {
public:
	string rn = "Technical Support";
	float salary_promo(float x) {
		return x += 1.0f;
	}
};

class Shopfloor :public employee {
public:
	string rn = "Shop Assistant";
};

int menu(array<employee*, max_employees> &listt,employeemanager boof)
{
	string choice;
	cout << "------------------------------------\nWelcome to the Employee Manager Menu\n------------------------------------";
	while (1)
	{
		cout << "\nPlease select an option.\n1) View Employees\n2) Add Employee\n3) Remove Employee\n4) Exit\n>>> ";
		getline(cin, choice);
		cin.clear();
		if (choice == "1" || choice == "View Employees")
		{
			boof.viewemployees(listt);
		}
		else if (choice == "2" || choice == "Add Employee")
		{
			boof.newemployee(listt);
		}
		else if (choice == "3" || choice == "Remove Employee")
		{
			cout << "Coming soon...";
		}
		else if (choice == "4" || choice == "Exit")
		{
			return 1;
		}
	}
	
}
int main()
{
	array<employee*, max_employees> list;
	employeemanager boof;

	employee* test[2];
	test[0] = new Manager();
	test[1] = new Amanager();
	int i = 0;
	test[i]->increase_salary(5);

	boof.initfile(list);
	menu(list, boof);

	boof.saveemployee(list);
}

