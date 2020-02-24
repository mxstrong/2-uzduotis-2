#pragma once
#include <vector>
#include <string>
#include "Student.h"
int calculateHomeworkCount(const std::string& input);
void readDataFromInput(int& n, std::vector<Student>& students);
void readDataFromFile(std::string fileName, int& n, std::vector<Student>& students);
void generateData(std::vector<Student>& students);
