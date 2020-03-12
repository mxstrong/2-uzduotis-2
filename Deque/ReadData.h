#pragma once
#include <deque>
#include <string>
#include "Student.h"
void readDataFromInput(int& n, std::deque<Student>& students);
void readDataFromFile(std::string fileName, int& n, std::deque<Student>& students);
void generateData(int n, std::deque<Student>& students);
