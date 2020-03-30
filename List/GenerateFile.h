#pragma once
#include <string>
#include <list>
#include "Student.h"

bool chooseToCalculate(std::list<Student>& students);
void generateFile(std::string fileName, std::list<Student> students);