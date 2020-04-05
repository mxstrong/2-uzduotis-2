#include <algorithm>
#include <iostream>
#include <filesystem>
#include "Student.h"
#include "Random.h"
#include "PrintResults.h"
#include "Choices.h"
#include "ReadData.h"
#include "Benchmark.h"

using namespace std::chrono;

int main()
{
  auto start = steady_clock::now();
  std::vector<Student> students;
  bool toBenchmark = chooseToBenchmark(students);
  if (toBenchmark)
  {
    doBenchmark();
  }
  else
  {
    std::string choice = chooseInputSource();

    if (choice == "skaityti")
    {
      readDataFromFile(students);
    }
    else if (choice == "generuoti")
    {
      generateData(students);
    }
    else
    {
      readDataFromInput(students);
    }
    std::vector<Student> badStudents;

    std::string final = chooseFinal();

    sortStudents(students);

    divideStudents(students, badStudents, final);

    printResultsToFile(students, "pazangus.txt", final);
    printResultsToFile(badStudents, "nepazangus.txt", final);
    
  }

  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Visos programos veikimo laikas: " << diff.count() << std::endl;
  system("pause");

  return 0;
}