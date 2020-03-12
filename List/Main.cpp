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
  std::list<Student> students;
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
        auto start = steady_clock::now();
        readDataFromFile(fileName, n, students);
        auto end = steady_clock::now();
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
    auto start = steady_clock::now();
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
        generateFile(fileName, students);
        
        auto end = steady_clock::now();
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
  std::list<Student> goodStudents;
  std::list<Student> badStudents;

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

  auto start = steady_clock::now();
  divideStudents(students, goodStudents, badStudents, final);
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Studentu dalijimas uztruko: " << diff.count() << std::endl;

  printResultsToFile(goodStudents, "pazangus.txt", final);
  printResultsToFile(badStudents, "nepazangus.txt", final);

  system("pause");

  return 0;
}