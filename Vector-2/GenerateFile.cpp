#include <chrono>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Student.h"
#include "GenerateFile.h"

using namespace std::chrono;

bool chooseToCalculate(std::vector<Student> &students)
{
  std::string calculateResults = "";

  while (calculateResults != "Taip")
  {
    std::cout << "Skaiciuoti rezultatus? (Taip / Ne)" << std::endl;
    std::cin >> calculateResults;
    if (calculateResults == "Ne")
    {
      std::string fileName;
      std::cout << "Iveskite generuojamo failo varda" << std::endl;
      std::cin >> fileName;
      generateFile(fileName, students);
      return false;
    }
  }
  return true;
}

void generateFile(std::string fileName, std::vector<Student> students)
{
  auto start = steady_clock::now();
  std::ofstream res(fileName.c_str());
  res << std::left
      << std::setw(15) << "Vardas"
      << std::setw(17) << "Pavarde";
  for (int i = 1; i <= students.front().homeworkResults.size(); i++)
  {
    res <<  "ND" << std::setw(5) << i << ' ';
  }
  res << "Egz." << std::endl;
  
  for (Student student : students)
  {
    std::ostringstream line;
    line << std::left << std::setw(15) << student.name
        << std::setw(17) << student.surname;
    for (int result : student.homeworkResults)
    {
      line << std::setw(8) << result;
    }
    line << student.examResult << std::endl;
    res << line.str();
  }
  res.close();
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Failu generavimas uztruko: " << diff.count() << std::endl;
}