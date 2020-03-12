#pragma once
#include <deque>
#include "Student.h"
#include <string>
void divideStudents(std::deque<Student>& students, std::deque<Student>& goodStudents, std::deque<Student>& badStudents, std::string final);
void printResultsToFile(std::deque<Student>& students, std::string fileName, std::string final);
