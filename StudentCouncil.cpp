#include "pch.h"
#include "StudentCouncil.h"

StudentCouncil::StudentCouncil(const string & firstname, const string & lastname, const string& patronymic, unsigned const age)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->patronymic = patronymic;
	this->age = age;
}
int StudentCouncil::getScore()
{
	return 1 + rand() % (6 - 2);
}

int StudentCouncil::getReScore()
{
	return 3 + rand() % (6 - 3);
}
