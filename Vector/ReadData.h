#pragma once
#include <vector>
#include <string>
#include "Student.h"
void readDataFromInput(int& n, std::vector<Student>& students);
void readDataFromFile(std::string fileName, int& n, std::vector<Student>& students);
void generateData(int n, std::vector<Student>& students);
