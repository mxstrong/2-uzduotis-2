#pragma once
#include <string>
#include <vector>
#include "Student.h"

bool chooseToCalculate(std::vector<Student>& students);
void generateFile(std::string fileName, std::vector<Student> students);