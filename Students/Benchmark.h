#pragma once
#include <string>
#include <vector>
#include "Student.h"

struct BenchmarkData
{
  int studentCount = 0;
  std::string fileName;
};

void doBenchmark();
void generateData(std::vector<Student>& students, int n);
void generateFile(std::string fileName, std::vector<Student> students);