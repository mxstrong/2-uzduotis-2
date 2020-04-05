#pragma once
#include <string>
#include <list>
#include "Student.h"

struct BenchmarkData
{
  int studentCount = 0;
  std::string fileName;
};

void doBenchmark();
void generateData(std::list<Student>& students, int n);
void generateFile(std::string fileName, std::list<Student> students);