#pragma once
#include <deque>
#include <string>
#include "Student.h"

void readDataFromInput(std::deque<Student>& students);
void readDataFromFile(std::deque<Student>& students);
void generateData(std::deque<Student>& students);
