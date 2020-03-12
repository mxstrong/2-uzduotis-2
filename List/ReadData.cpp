#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include "Student.h"
#include "Random.h"

int calculateHomeworkCount(const std::string& input)
{
  int homeworkCount = 0;
  const size_t step = 2;
  size_t position = 0;
  while ((position = input.find("ND", position)) != std::string::npos) {
    position += step;
    ++homeworkCount;
  }

  return homeworkCount;
}

// Read data from console input
void readDataFromInput(int& n, std::list<Student>& students)
{
  std::cout << "Iveskite studentu kieki: " << std::endl;
  std::cin >> n;
  for (int i = 0; i < n; i++)
  {
    Student student;
    std::cout << "Iveskite studento varda: " << std::endl;
    std::cin >> student.name;
    std::cout << "Iveskite studento pavarde: " << std::endl;
    std::cin >> student.surname;
    std::cout << "Iveskite namu darbu rezultatus, kai baigsite iveskite -1 arba kita neigiama skaiciu: " << std::endl;

    int j = 0;
    int result;
    do
    {
      std::cin >> result;
      if (result >= 0 && result <= 10) 
      {
        student.homeworkResults.push_back(result);
      }
      else
      {
        std::cout << "Pazymys turi buti skaicius nuo 1 iki 10" << std::endl;
      }
      j++;
    } while (result >= 0);

    std::cout << "Iveskite egzamino rezultata: " << std::endl;
    std::cin >> student.examResult;

    students.push_back(student);
  }
}

// Read data from file
void readDataFromFile(std::string fileName, int& n, std::list<Student>& students)
{
  std::string input;
  std::ifstream f(fileName.c_str());
  std::stringstream buffer;
  buffer << f.rdbuf();
  f.close();
  std::getline(buffer, input);
  if (input.empty())
  {
    return;
  }
  int homeworkCount = calculateHomeworkCount(input);
  int i = 0;

  while (buffer)
  {
    if (!buffer.eof())
    {
      std::getline(buffer, input);
      Student student;
      std::istringstream inputStream(input);
      inputStream >> student.name >> student.surname;
      for (int j = 0; j < homeworkCount; j++)
      {
        int result;
        inputStream >> result;
        student.homeworkResults.push_back(result);
      } 
      inputStream >> student.examResult;
      students.push_back(student);
      i++;
    }
    else 
    {
      break;
    }
  }
  f.close();
  n = i + 1;
}

void generateData(int n, std::list<Student>& students)
{
  int homeworkCount = generateRandomInt(1, 20);
  std::list<std::string> names{ "Vardenis", "Vardas", "Vardukas", "Vardiklis", "Vardonis", "Vardanas", "Vardauskas" };
  std::list<std::string> surnames{ "Pavardenis", "Pavarde", "Pavardukas", "Pavardiklis", "Pavardonis", "Pavardanas", "Pavardauskas" };
  for (int i = 0; i < n; i++)
  {
    Student student;
    int random = generateRandomInt(0, 6);
    auto namesIterator = names.begin();
    std::advance(namesIterator, random);
    student.name = *namesIterator;

    random = generateRandomInt(0, 6);
    auto surnamesIterator = surnames.begin();
    std::advance(surnamesIterator, random);
    student.surname = *surnamesIterator;

    for (int j = 0; j < homeworkCount; j++)
    {
      int result = generateRandomInt(0, 10);
      student.homeworkResults.push_back(result);
    }

    student.examResult = generateRandomInt(0, 10);
    students.push_back(student);
  }
}