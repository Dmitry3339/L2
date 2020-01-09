#pragma once
#include "Student.h"
#include "StudentOrdinary.h"

class StudentCouncil : public StudentOrdinary
{
public:
	StudentCouncil() = delete;

	StudentCouncil(const std::string & t_firstname, const std::string & t_lastname, const std::string& t_patronymic, unsigned const t_age);

	int getScore() override;
	int getReScore() override;

	virtual ~StudentCouncil() = default;
};

