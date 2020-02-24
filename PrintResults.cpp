#include <vector>
#include <iomanip>
#include <fstream>
#include "Student.h"
#include <algorithm>

bool isFirst(Student first, Student second)
{
  if (first.name < second.name)
  {
    return true;
  }
  else if (second.name < first.name)
  {
    return false;
  }
  else
  {
    return (first.surname < second.surname) ? true : false;
  }
}

void printResultsToFile(int n, std::vector<Student> students)
{
  std::ofstream res("rezultatai.txt");
  res << std::left
    << std::setw(15) << "Vardas"
    << std::setw(17) << "Pavarde"
    << std::setw(17) << "Galutinis (Vid.) "
    << std::setw(16) << "Galutinis (Med.)"
    << std::endl;
  for (int i = 0; i < 65; i++)
  {
    res << '-';
  }
  res << std::endl;
  std::sort(students.begin(), students.end(), isFirst);
  for (Student student : students)
  {
    res << std::setw(15) << student.name
      << std::setw(17) << student.surname
      << std::fixed << std::setprecision(2) << std::setw(17) << student.getAverage()
      << std::setw(16) << student.getMedian()
      << std::endl;
  }
  res.close();
}