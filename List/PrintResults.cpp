#include <chrono>
#include <list>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Student.h"
#include <algorithm>

using namespace std::chrono;

std::string chooseFinal()
{
  std::string final = "";
  bool badInput = false;

  do
  {
    if (badInput) {
      std::cout << "Pasirinkote negalima pasirinkima. Galimi pasirinkimai: vidurkis, mediana" << std::endl;
    }
    std::cout << "Pasirinkite galutini bala (vidurkis / mediana)" << std::endl;
    std::cin >> final;
    badInput = !(final.compare("vidurkis") == 0 || final.compare("mediana") == 0);
  } while (badInput);
  return final;
}

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

void sortStudents(std::list<Student>& students)
{
  auto start = steady_clock::now();
  students.sort(isFirst);
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Studentu rikiavimas uztruko: " << diff.count() << std::endl;
}

void printResultsToFile(std::list<Student>& students, std::string fileName, std::string final)
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