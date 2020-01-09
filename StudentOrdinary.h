#pragma once
#include "Student.h"

class StudentOrdinary :public Student
{
public:
	StudentOrdinary() {}

	StudentOrdinary(const std::string & t_firstname, const std::string & t_lastname, const std::string& t_patronymic, unsigned const t_age);

	int getScore() override;
	int getReScore() override;

	virtual ~StudentOrdinary() = default;
};

