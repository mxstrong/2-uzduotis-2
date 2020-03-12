#pragma once
#include <vector>
#include "Student.h"
#include <string>
void divideStudents(std::vector<Student>& students, std::vector<Student>& goodStudents, std::vector<Student>& badStudents, std::string final);
void printResultsToFile(std::vector<Student>& students, std::string fileName, std::string final);
