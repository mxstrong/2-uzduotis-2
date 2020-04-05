#include <chrono>
#include <deque>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Student.h"
#include <algorithm>

using namespace std::chrono;

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

void divideStudents(std::deque<Student> &students, std::deque<Student> &goodStudents, std::deque<Student> &badStudents, std::string final)
{
  auto start = steady_clock::now();
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
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Studentu dalijimas uztruko: " << diff.count() << std::endl;
}

void sortStudents(std::deque<Student>& students)
{
  auto start = steady_clock::now();
  std::sort(students.begin(), students.end(), isFirst);
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Studentu rikiavimas uztruko: " << diff.count() << std::endl;
}

void printResultsToFile(std::deque<Student>& students, std::string fileName, std::string final)
{
  auto start = steady_clock::now();
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

  for (Student student : students)
  {
    res << student << std::endl;
  }
  res.close();
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Studentu surasymas i faila " << fileName << " uztruko: " << diff.count() << std::endl;
}