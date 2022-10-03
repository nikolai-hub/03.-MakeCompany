#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H

#include <vector>
#include <string>
#include <utility>
#include <cstddef>
#include <sstream>
#include <memory>

#include "Company.h"
typedef std::vector<std::string> VecStr;
typedef std::vector < std::pair<char, char>> EmployeeName;

int toInt(const std::string& s) {
	int number = 0;
	std::istringstream(s) >> number;
	return number;
}

std::shared_ptr<Company> makeCompany(VecStr properties) {
	int id = toInt(properties[0]);
	std::string name = properties[1];
	EmployeeName employeeInitials;
	for (size_t i = 2; i < properties.size(); i++)
	{
		std::string initialsPair = properties[i];
		employeeInitials.push_back(std::pair<char, char> {initialsPair[0], initialsPair[1]});
	}
	return std::shared_ptr<Company>(new Company(id, name, employeeInitials));
}


#endif // !MAKE_COMPANY_H
