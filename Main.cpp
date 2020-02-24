#include <iostream>
#include <filesystem>
#include "Student.h"
#include "Random.h"
#include "PrintResults.h"
#include "ReadData.h"

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
        readDataFromFile(fileName, n, students);
      } catch(std::exception &e)
      {
        if (!std::filesystem::exists(fileName))
        {
          std::cout << "Failas su tokiu pavadinimu neegzistuoja";
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
    generateData(students);
  }
  else
  {
    readDataFromInput(n, students);
  }
  printResultsToFile(n, students);
  return 0;
}