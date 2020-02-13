#pragma once
#include <string>
#include <fstream>
#include <array>

const int max_employees = 20;

class employee {
public:
	std::string rn = "N/A";
	std::string name;
	std::string address;
	std::string phone[2];
	std::string DoB;
	std::string Employment;
	virtual float increase_salary(float x);
};

class employeemanager {
public:
	void initfile(std::array<employee*, max_employees> &listt);
	void saveemployee(std::array<employee*, max_employees> &listt);
	void newemployee(std::array<employee*, max_employees> &listt);
	void viewemployees(std::array<employee*, max_employees> &listt);
};