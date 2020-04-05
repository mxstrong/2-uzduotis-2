#pragma once
#include <string>
#include <deque>
#include "Student.h"

struct BenchmarkData
{
  int studentCount = 0;
  std::string fileName;
};

void doBenchmark();
void generateData(std::deque<Student>& students, int n);
void generateFile(std::string fileName, std::deque<Student> students);