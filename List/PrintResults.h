#pragma once
#include <list>
#include "Student.h"
#include <string>
void divideStudents(std::list<Student>& students, std::list<Student>& goodStudents, std::list<Student>& badStudents, std::string final);
void printResultsToFile(std::list<Student>& students, std::string fileName, std::string final);
