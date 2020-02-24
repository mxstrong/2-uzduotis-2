#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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
void readDataFromInput(int& n, std::vector<Student>& students)
{
  std::cout << "Iveskite studentu kieki: " << std::endl;
  std::cin >> n;
  for (int i = 0; i < n; i++)
  {
    Student student;
    students.push_back(student);
    std::cout << "Iveskite studento varda: " << std::endl;
    std::cin >> students[i].name;
    std::cout << "Iveskite studento pavarde: " << std::endl;
    std::cin >> students[i].surname;
    std::cout << "Iveskite namu darbu rezultatus, kai baigsite iveskite -1 arba kita neigiama skaiciu: " << std::endl;

    int j = 0;
    int result;
    do
    {
      std::cin >> result;
      if (result >= 0 && result <= 10) 
      {
        students[i].homeworkResults.push_back(result);
      }
      else
      {
        std::cout << "Pazymys turi buti skaicius nuo 1 iki 10" << std::endl;
      }
      j++;
    } while (result >= 0);

    std::cout << "Iveskite egzamino rezultata: " << std::endl;
    std::cin >> students[i].examResult;
  }
}

// Read data from file
void readDataFromFile(std::string fileName, int& n, std::vector<Student>& students)
{
  std::string input;
  std::ifstream f(fileName.c_str());
  std::getline(f, input);
  if (input.empty())
  {
    return;
  }
  int homeworkCount = calculateHomeworkCount(input);
  int i = 0;

  while (std::getline(f, input))
  {
    // std::cout << i << ' ' << input << std::endl;
    if (input.empty())
    {
      break;
    }
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
  f.close();
  n = i + 1;
}

void generateData(std::vector<Student>& students)
{
  int n = generateRandomInt(1, 100);
  int homeworkCount = generateRandomInt(1, 20);
  std::vector<std::string> names{ "Vardenis", "Vardas", "Vardukas", "Vardiklis", "Vardonis", "Vardanas", "Vardauskas" };
  std::vector<std::string> surnames{ "Pavardenis", "Pavarde", "Pavardukas", "Pavardiklis", "Pavardonis", "Pavardanas", "Pavardauskas" };
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
      std::cout << result << std::endl;
      student.homeworkResults.push_back(result);
    }

    student.examResult = generateRandomInt(0, 10);
    std::cout << "Egzamino rezultatas: " << student.examResult << std::endl;
    students.push_back(student);
  }
}