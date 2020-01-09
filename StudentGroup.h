#pragma once
#include <vector>
#include <string>
#include "Student.h"
#include "StudentBotan.h"
#include "StudentCouncil.h"
#include "StudentOrdinary.h"

class StudentGroup
{
private:
	vector<Student*> students;
	std::vector<Student*> reExamList;
	std::string namegroup;
	int minAge = 0;
	double minAverageScore = 0.0;
	const int MaximumStudents = 20;
	bool StudentSearch(Student* student);
public:
	StudentGroup() = delete;
	StudentGroup(const std::string& t_namegroup) : namegroup(t_namegroup) {}

	Student* getStudent(const std::string& t_firstname, const std::string& t_lastname, const std::string& t_patronymic);
	const size_t& getStudentsCount();
	const std::vector<Student*>& getStudentsList();
	const string& getNameGroup();

	void addStudent(Student* student);
	void removeStudent(Student* student);
	void Exam();
	void ReExam();

	virtual ~StudentGroup() = default;
};

std::ostream& operator<< (std::ostream& out, StudentGroup& group);
