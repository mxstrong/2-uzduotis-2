#pragma once
#include <list>
#include <string>
#include "Student.h"
void readDataFromInput(int& n, std::list<Student>& students);
void readDataFromFile(std::string fileName, int& n, std::list<Student>& students);
void generateData(int n, std::list<Student>& students);
