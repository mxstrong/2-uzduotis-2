#pragma once
#include <list>
#include <string>
#include "Student.h"

std::string chooseInputSource();
void readDataFromInput(std::list<Student>& students);
void readDataFromFile(std::list<Student>& students);
void generateData(std::list<Student>& students);
