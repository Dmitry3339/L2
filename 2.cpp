// 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "studentgroup.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	StudentBotan* abramovich = new StudentBotan("Вадим", "Абрамович", "Иванович", 18);
	StudentBotan* zuyev = new StudentBotan("Никита", "Зуев", "Сергеевич", 22);
	StudentBotan* romanov = new StudentBotan("Василий", "Романов", "Алексеевич", 17);

	StudentCouncil* dudnik = new StudentCouncil("Борис", "Дудник", "Петрович", 16);
	StudentCouncil* sutulin = new StudentCouncil("Афанасий", "Сутулин", "Александрович", 19);
	StudentCouncil* shatalov = new StudentCouncil("Генадий", "Шаталов", "Николаевич", 17);

	StudentOrdinary* korolyov = new StudentOrdinary("Гавриил", "Королев", "Михайлович", 25);
	StudentOrdinary* astakhov = new StudentOrdinary("Глеб", "Астахов", "Георгиевич", 18);
	StudentOrdinary* fedorov = new StudentOrdinary("Павел", "Федоров", "Федорович", 18);

	StudentBotan *Rkorolyov = abramovich->Botan();
	StudentCouncil *Rabramovich = dudnik->Council();
	StudentOrdinary *Rdudnik = korolyov->Ordinary();

	StudentGroup math = { "Mатематика" };

	math.addStudent(Rkorolyov);
	math.addStudent(Rabramovich);
	math.addStudent(Rdudnik);

	math.addStudent(abramovich);
	math.addStudent(zuyev);
	math.addStudent(romanov);

	math.addStudent(dudnik);
	math.addStudent(sutulin);
	math.addStudent(shatalov);

	math.addStudent(korolyov);
	math.addStudent(astakhov);
	math.addStudent(fedorov);

	std::cout << math;

	math.Exam();

	math.ReExam();

	std::cout << math;

	delete abramovich, zuyev, romanov, dudnik, sutulin, shatalov, korolyov, astakhov, fedorov;
	delete Rkorolyov,Rabramovich,Rdudnik;
	std::cin.get();
}