#include <vector>
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

void divideStudents(std::vector<Student> &students, std::vector<Student> &goodStudents, std::vector<Student> &badStudents)
{
  for (Student student : students)
  {
    if (student.getFinal(student.getAverage(), student.examResult) >= 5)
    {
      goodStudents.push_back(student);
    }
    else
    {
      badStudents.push_back(student);
    }
  }
}

void printResultsToFile(std::vector<Student> &students, std::string fileName)
{
  std::ofstream res(fileName.c_str());
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
  std::sort(students.begin(), students.end(), isFirst);
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