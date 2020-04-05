#pragma once
#include <deque>
#include "Student.h"
#include <string>

bool isFirst(Student first, Student second);
void divideStudents(std::deque<Student>& students, std::deque<Student>& goodStudents, std::deque<Student>& badStudents, std::string final);
void sortStudents(std::deque<Student>& students);
void printResultsToFile(std::deque<Student>& students, std::string fileName, std::string final);
