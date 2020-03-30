#pragma once
#include <string>
#include <deque>
#include "Student.h"

bool chooseToCalculate(std::deque<Student>& students);
void generateFile(std::string fileName, std::deque<Student> students);