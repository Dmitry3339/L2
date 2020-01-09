#pragma once
#include <iostream>
#include <array>
#include <string>

using namespace std;

class StudentBotan;
class StudentOrdinary;
class StudentCouncil;

class Student
{
public:
	Student() {};

	Student(const string& t_firstname, const string& t_lastname, const string& t_patronymic, unsigned const t_age) :
		firstname(t_firstname), lastname(t_lastname), patronymic(t_patronymic), age(t_age) {}

	StudentBotan* Botan();
	StudentOrdinary* Ordinary();
	StudentCouncil* Council();

	const std::string& getFirstName();
	const std::string& getLastName();
	const std::string& getPatronymic();
	unsigned getAge();

	void setFirstName(const std::string& firstname);
	void setLastName(const std::string& lastname);
	void setPatronymic(const std::string& patronymic);
	void setAge(unsigned age);

	void increaseGroupJoins();
	void decreaseGroupJoins();

	virtual int getScore() = 0;
	virtual int getReScore() = 0;

	virtual ~Student() = default;

protected:
	string firstname;
	string lastname;
	string patronymic;
	unsigned age = 0;
	unsigned groupJoins = 0;
};
