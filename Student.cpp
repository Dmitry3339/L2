#include "pch.h"
#include "Student.h"
#include "StudentCouncil.h"
#include "StudentBotan.h"
#include "StudentOrdinary.h"

StudentOrdinary * Student::Ordinary()
{
	return new StudentOrdinary(firstname, lastname, patronymic, age);
}

StudentCouncil * Student::Council()
{
	return new StudentCouncil(firstname, lastname, patronymic, age);
}

StudentBotan * Student::Botan()
{
	return new StudentBotan(firstname, lastname, patronymic, age);
}

const std::string& Student::getFirstName()
{
	return this->firstname;
}

const std::string& Student::getLastName()
{
	return this->lastname;
}

const std::string& Student::getPatronymic()
{
	return this->patronymic;
}

unsigned Student::getAge()
{
	return this->age;
}

void Student::setFirstName(const std::string& firstname)
{
	this->firstname = firstname;
}

void Student::setLastName(const std::string& lastname)
{
	this->lastname = lastname;
}

void Student::setPatronymic(const std::string& patronymic)
{
	this->patronymic = patronymic;
}

void Student::setAge(unsigned age)
{
	this->age = age;
}


void Student::increaseGroupJoins()
{
	groupJoins++;
}

void Student::decreaseGroupJoins()
{
	groupJoins--;
}