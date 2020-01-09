#pragma once
#include "Student.h"
using namespace std;

class StudentBotan :public Student
{
public:
	StudentBotan(const std::string & t_firstname, const std::string & t_lastname, const std::string& t_patronymic, unsigned const t_age);

	int getScore() override;
	int getReScore() override;

	virtual ~StudentBotan() = default;
};

