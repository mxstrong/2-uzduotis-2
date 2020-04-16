#include "Choices.h"
#include "Benchmark.h"

bool chooseToBenchmark(std::vector<Student>& students)
{
  std::string toDoBenchmark = "";

  while (toDoBenchmark != "Taip")
  {
    std::cout << "Daryti programos veikimo laiko analize? (Taip / Ne)" << std::endl;
    std::cin >> toDoBenchmark;
    if (toDoBenchmark == "Ne")
    {
      return false;
    }
  }
  return true;
}

std::string chooseInputSource()
{
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
  return choice;
}