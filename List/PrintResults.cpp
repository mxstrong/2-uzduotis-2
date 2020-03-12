#include <list>
#include <iomanip>
#include <iostream>
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

void divideStudents(std::list<Student> &students, std::list<Student> &goodStudents, std::list<Student> &badStudents, std::string final)
{
  for (Student student : students)
  {
    if (student.getFinal((final == "vidurkis") ? student.getAverage() : student.getMedian(), student.examResult) >= 5)
    {
      goodStudents.push_back(student);
    }
    else
    {
      badStudents.push_back(student);
    }
  }
}

void printResultsToFile(std::list<Student> &students, std::string fileName, std::string final)
{
  std::ofstream res(fileName.c_str());
  

  res << std::left
      << std::setw(15) << "Vardas"
      << std::setw(17) << "Pavarde"
      << std::setw(17) << ((final == "vidurkis") ? "Galutinis(Vid.)" : "Galutinis (Med.)")
      << std::endl;
  for (int i = 0; i < 65; i++)
  {
    res << '-';
  }
  res << std::endl;
  students.sort(isFirst);
  for (Student student : students)
  {
    res << std::setw(15) << student.name
      << std::setw(17) << student.surname
      << std::fixed << std::setprecision(2) << std::setw(17)
      << student.getFinal((final == "vidurkis") ? student.getAverage() : student.getMedian(), student.examResult)
      << std::endl;
  }
  res.close();
}