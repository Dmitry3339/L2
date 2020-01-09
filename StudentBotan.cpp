#include "pch.h"
#include "StudentBotan.h"

StudentBotan::StudentBotan(const string & firstname, const string & lastname, const string& patronymic, unsigned const age)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->patronymic = patronymic;
	this->age = age;
}

int StudentBotan::getScore()
{
	return 4 + rand() % (5 - 4);
}

int StudentBotan::getReScore()
{
	return 4 + rand() % (5 - 4);
}
