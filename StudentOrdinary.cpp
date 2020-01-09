#include "pch.h"
#include "StudentOrdinary.h"

StudentOrdinary::StudentOrdinary(const string & firstname, const string & lastname, const string& patronymic, unsigned const age)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->patronymic = patronymic;
	this->age = age;
}

int StudentOrdinary::getScore()
{
	return 1 + rand() % (6 - 2);
}

int StudentOrdinary::getReScore()
{
	return 1 + rand() % (6 - 2);
}
