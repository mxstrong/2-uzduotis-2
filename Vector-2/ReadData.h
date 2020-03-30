#pragma once
#include <vector>
#include <string>
#include "Student.h"

std::string chooseInputSource();
void readDataFromInput(std::vector<Student>& students);
void readDataFromFile(std::vector<Student>& students);
void generateData(std::vector<Student>& students);
