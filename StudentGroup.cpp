#include "pch.h"
#include "StudentGroup.h"

bool StudentGroup::StudentSearch(Student* student)
{
	for (auto it = students.begin(); it != students.end(); ++it)
		if (*it == student)
			return true;
	return false;
}

Student* StudentGroup::getStudent(const string& t_firstname, const string& t_lastname, const string& t_patronymic)
{
	for (auto& i : students)
		if ((i->getFirstName() == t_firstname) && (i->getLastName() == t_lastname) && (i->getPatronymic() == t_patronymic))
			return i;
	return nullptr;
}

const size_t & StudentGroup::getStudentsCount()
{
	return students.size();
}

const std::vector<Student*>& StudentGroup::getStudentsList()
{
	return students;
}

const string & StudentGroup::getNameGroup()
{
	return namegroup;
}

void StudentGroup::addStudent(Student* student)
{
	if (students.size() >= MaximumStudents)
	{
		std::cout << "���������� �������� �������� " << student->getLastName() << " � ������ ��� ��� ��� ��������� \n";
		return;
	}
	if (StudentSearch(student))
	{
		std::cout << "������� " << student->getLastName() << " " << student->getFirstName() << " " << student->getPatronymic() << " ��� ��������� � ������\n";
		return;
	}
	student->increaseGroupJoins();
	students.push_back(student);
	std::cout << "������� " << student->getLastName() << " " << student->getFirstName() << " " << student->getPatronymic() << " ";
	std::cout << "�������� � ������ " << namegroup << "\n";
}

void StudentGroup::removeStudent(Student* student)
{
	for (auto it = students.begin(); it != students.end(); ++it)
	{
		if (*it == student)
		{
			student->decreaseGroupJoins();
			students.erase(it);
			std::cout << "������� " << student->getLastName() << " " << student->getFirstName() << " " << student->getPatronymic() << " ";
			std::cout << "������ �� ������ " << namegroup << "\n";
			return;
		}
	}
	std::cout << "������� " << student->getLastName() << " " << student->getFirstName() << " " << student->getPatronymic() << " �� �������� ������ ���� ������ \n";
}

void StudentGroup::Exam()
{
	for (auto& i : students)
		if (i->getScore() <= 2)
			reExamList.push_back(i);
}

void StudentGroup::ReExam()
{
	for (auto it = reExamList.begin(); it != reExamList.end(); ++it)
		if ((*it)->getReScore() <= 2)
			removeStudent(*it);

	reExamList.clear();
}

std::ostream & operator<<(std::ostream & out, StudentGroup & group)
{
	std::vector<Student*> student = group.getStudentsList();
	out << "\n ������ ��������� ������ : " << group.getNameGroup() <<": \n";

	for (auto& i : student)
		out << i->getLastName() << " " << i->getFirstName() << " " << i->getPatronymic() << std::endl;;

	out << "��������� � ������: " << group.getStudentsCount() << ".\n";

	return out;
}