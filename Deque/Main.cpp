#include <algorithm>
#include <iostream>
#include <filesystem>
#include "Student.h"
#include "Random.h"
#include "PrintResults.h"
#include "GenerateFile.h"
#include "ReadData.h"

using namespace std::chrono;

int main()
{
  auto start = steady_clock::now();
  std::deque<Student> students;
  std::string choice = chooseInputSource();

  if (choice == "skaityti")
  {
    readDataFromFile(students);
  }
  else if (choice == "generuoti")
  {
    generateData(students);
    bool choice = chooseToCalculate(students);
    if (!choice)
    {
      auto end = steady_clock::now();
      duration<double> diff = end - start;
      std::cout << "Visos programos veikimo laikas: " << diff.count() << std::endl;

      system("pause");

      return 0;
    }
  }
  else
  {
    readDataFromInput(students);
  }
  std::deque<Student> badStudents;
  std::deque<Student> goodStudents;
  std::string final = chooseFinal();

  sortStudents(students);

  divideStudents(students, goodStudents, badStudents, final);

  printResultsToFile(students, "pazangus.txt", final);
  printResultsToFile(badStudents, "nepazangus.txt", final);
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Visos programos veikimo laikas: " << diff.count() << std::endl;

  system("pause");

  return 0;
}