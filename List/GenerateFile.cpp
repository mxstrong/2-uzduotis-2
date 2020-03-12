#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include "Student.h"
#include "GenerateFile.h"

void generateFile(std::string fileName, std::list<Student> students)
{
  std::ofstream res(fileName.c_str());
  res << std::left
      << std::setw(15) << "Vardas"
      << std::setw(17) << "Pavarde";
  for (int i = 1; i <= students.front().homeworkResults.size(); i++)
  {
    res << std::setw(8) << "ND" << i << ' ';
  }
  res << "Egz." << std::endl;
  for (Student student : students)
  {
    res << std::setw(15) << student.name
        << std::setw(17) << student.surname;
    for (int result : student.homeworkResults)
    {
      res << std::setw(8) << result;
    }
    res << student.examResult << std::endl;
  }
  res.close();
}