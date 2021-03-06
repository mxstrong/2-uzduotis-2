#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Student.h"
#include <algorithm>
#include <chrono>

using namespace std::chrono;

bool isFirst(Student first, Student second)
{
  if (first.getName() < second.getName())
  {
    return true;
  }
  else if (second.getName() < first.getName())
  {
    return false;
  }
  else
  {
    return (first.getSurname() < second.getSurname()) ? true : false;
  }
}

void divideStudents(std::vector<Student> &goodStudents, std::vector<Student> &badStudents)
{
  auto start = steady_clock::now();
  auto p = std::stable_partition(goodStudents.begin(), goodStudents.end(),
    [&](Student student) { return student.getFinal() >= 5; });
  
  badStudents.insert(badStudents.end(), std::make_move_iterator(p), std::make_move_iterator(goodStudents.end()));
  goodStudents.erase(p, goodStudents.end());
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Studentu dalijimas uztruko: " << diff.count() << std::endl;
}

void sortStudents(std::vector<Student>& students)
{
  auto start = steady_clock::now();
  std::sort(students.begin(), students.end(), isFirst);
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Studentu rikiavimas uztruko: " << diff.count() << std::endl;
}

void printResultsToFile(std::vector<Student> &students, std::string fileName)
{
  auto start = steady_clock::now();
  std::ofstream res(fileName.c_str());

  res << std::left
    << std::setw(15) << "Vardas"
    << std::setw(17) << "Pavarde"
    << std::setw(17) << ((Student::getMedianOrAverage() == "vidurkis") ? "Galutinis(Vid.)" : "Galutinis (Med.)")
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