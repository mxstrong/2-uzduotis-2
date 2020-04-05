#pragma once
#include <list>
#include "Student.h"
#include <string>

bool isFirst(Student first, Student second);
void divideStudents(std::list<Student>& goodStudents, std::list<Student>& badStudents, std::string final);
void sortStudents(std::list<Student>& students);
void printResultsToFile(std::list<Student>& students, std::string fileName, std::string final);
