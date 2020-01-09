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
		std::cout << "Невозможно добавить студента " << student->getLastName() << " в группу так как она заполнена \n";
		return;
	}
	if (StudentSearch(student))
	{
		std::cout << "Студент " << student->getLastName() << " " << student->getFirstName() << " " << student->getPatronymic() << " уже находится в группе\n";
		return;
	}
	student->increaseGroupJoins();
	students.push_back(student);
	std::cout << "Студент " << student->getLastName() << " " << student->getFirstName() << " " << student->getPatronymic() << " ";
	std::cout << "добавлен в группу " << namegroup << "\n";
}

void StudentGroup::removeStudent(Student* student)
{
	for (auto it = students.begin(); it != students.end(); ++it)
	{
		if (*it == student)
		{
			student->decreaseGroupJoins();
			students.erase(it);
			std::cout << "Студент " << student->getLastName() << " " << student->getFirstName() << " " << student->getPatronymic() << " ";
			std::cout << "удален из группы " << namegroup << "\n";
			return;
		}
	}
	std::cout << "Студент " << student->getLastName() << " " << student->getFirstName() << " " << student->getPatronymic() << " не является членом этой группы \n";
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
	out << "\n Список студентов группы : " << group.getNameGroup() <<": \n";

	for (auto& i : student)
		out << i->getLastName() << " " << i->getFirstName() << " " << i->getPatronymic() << std::endl;;

	out << "Студентов в группе: " << group.getStudentsCount() << ".\n";

	return out;
}