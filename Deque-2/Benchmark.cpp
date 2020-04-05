#include <chrono>
#include <fstream>
#include <string>
#include <deque>
#include <iomanip>
#include "Student.h"
#include "Benchmark.h"
#include "PrintResults.h"
#include "Choices.h"
#include "Benchmark.h"
#include "Random.h"

using namespace std::chrono;

void doBenchmark()
{
  int fileCount = -1;
  while (fileCount < 0)
  {
    std::cout << "Iveskite kiek failu generuoti: " << std::endl;
    std::cin >> fileCount;
    if (fileCount < 0)
    {
      throw "Negalima generuoti neigiamo failu skaiciaus";
    }
  }
  std::deque<BenchmarkData> benchmarkData(fileCount, BenchmarkData());
  std::cout << "Iveskite kokio dydzio failus generuoti: " << std::endl;
  for (auto& data : benchmarkData)
  {
    std::cin >> data.studentCount;
  }
  std::cout << "Iveskite failu vardus: " << std::endl;
  for (auto& data : benchmarkData)
  {
    std::cin >> data.fileName;
  }
  std::string final = chooseFinal();
  for (auto data : benchmarkData)
  {
    auto start = steady_clock::now();
    std::deque<Student> students;
    generateData(students, data.studentCount);
    generateFile(data.fileName, students);
    sortStudents(students);
    std::deque<Student> badStudents;
    divideStudents(students, badStudents, final);
    printResultsToFile(students, "pazangus.txt", final);
    printResultsToFile(badStudents, "nepazangus.txt", final);
    auto end = steady_clock::now();
    duration<double> diff = end - start;
    std::cout << "Laiko matavimas su " << data.studentCount << " studentu uztruko: " << diff.count() << std::endl;
  }
}

void generateData(std::deque<Student>& students, int n)
{
  auto start = steady_clock::now();
  int homeworkCount = generateRandomInt(1, 20);
  std::deque<std::string> names{ "Vardenis", "Vardas", "Vardukas", "Vardiklis", "Vardonis", "Vardanas", "Vardauskas" };
  std::deque<std::string> surnames{ "Pavardenis", "Pavarde", "Pavardukas", "Pavardiklis", "Pavardonis", "Pavardanas", "Pavardauskas" };
  for (int i = 0; i < n; i++)
  {
    Student student;
    int random = generateRandomInt(0, 6);
    student.name = names[random];
    random = generateRandomInt(0, 6);
    student.surname = surnames[random];

    for (int j = 0; j < homeworkCount; j++)
    {
      int result = generateRandomInt(0, 10);
      student.homeworkResults.push_back(result);
    }

    student.examResult = generateRandomInt(0, 10);
    students.push_back(student);
  }
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << n << " studentu generavimas uztruko: " << diff.count() << std::endl;
}

void generateFile(std::string fileName, std::deque<Student> students)
{
  auto start = steady_clock::now();
  std::ofstream res(fileName.c_str());
  res << std::left
    << std::setw(15) << "Vardas"
    << std::setw(17) << "Pavarde";
  for (int i = 1; i <= students.front().homeworkResults.size(); i++)
  {
    res << "ND" << std::setw(5) << i << ' ';
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