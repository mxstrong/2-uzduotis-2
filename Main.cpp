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
  int n = 0;
  std::vector<Student> students;
  bool goodChoice = true;
  std::string choice;
  do {
    if (!goodChoice)
    {
      std::cout << "Pasirinkimas turi buti ivesti, generuoti arba skaityti" << std::endl;
    }
    std::cout << "Kaip gauti duomenis (ivesti, generuoti, skaityti(is failo))?" << std::endl;
    std::cin >> choice;
    goodChoice = choice.compare("ivesti") == 0 || choice.compare("generuoti") == 0 || choice.compare("skaityti") == 0;
  } while (!goodChoice);
  if (choice == "skaityti")
  {
    bool fileExists = false;
    do {
      fileExists = true;
      std::string fileName;
      std::cout << "Iveskite failo varda: " << std::endl;
      std::cin >> fileName;
      try 
      {
        auto start = high_resolution_clock::now();
        readDataFromFile(fileName, n, students);
        auto end = high_resolution_clock::now();
        duration<double> diff = end - start;
        std::cout << "Duomenu nuskaitymas is failo uztruko: " << diff.count() << std::endl;
      } catch(std::exception &e)
      {
        if (!std::filesystem::exists(fileName))
        {
          std::cout << "Failas su tokiu pavadinimu neegzistuoja" << std::endl;
          fileExists = false;
        }
        else
        {
          throw;
        }
      }
    } while(!fileExists);
    
  } 
  else if (choice == "generuoti")
  {
    auto start = high_resolution_clock::now();
    std::cout << "Kiek studentu sugeneruoti?" << std::endl;
    std::cin >> n;
    if (n > 0)
    {
      generateData(n, students);
    }
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
        generateFile("Filename", students);
        
        auto end = high_resolution_clock::now();
        duration<double> diff = end - start;
        std::cout << "Failu generavimas uztruko: " << diff.count() << std::endl;
        return 0;
      }
    }
  }
  else
  {
    readDataFromInput(n, students);
  }
  std::vector<Student> goodStudents;
  std::vector<Student> badStudents;

  auto start = high_resolution_clock::now();
  divideStudents(students, goodStudents, badStudents);
  auto end = high_resolution_clock::now();
  duration<double> diff = end - start;
  std::cout << "Studentu dalijimas uztruko: " << diff.count() << std::endl;

  auto start = high_resolution_clock::now();
  printResultsToFile(goodStudents, "pazangus.txt");
  printResultsToFile(badStudents, "nepazangus.txt");
  auto end = high_resolution_clock::now();
  duration<double> diff = end - start;
  std::cout << "Studentu surasymas i 2 failus uztruko: " << diff.count() << std::endl;
  
  return 0;
}