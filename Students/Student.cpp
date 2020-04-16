#include "Student.h"
#include <algorithm>
#include <numeric>
#include <iomanip>

float Student::getAverage()
{
  if (homeworkResults.size() == 0)
  {
    return 0.6 * examResult;
  }
  return (std::accumulate(homeworkResults.begin(), homeworkResults.end(), 0.0) / (homeworkResults.size()) * 0.4) + 0.6 * examResult;
}

float Student::getMedian()
{
  if (homeworkResults.size() == 0)
  {
    return 0;
  }
  std::sort(homeworkResults.begin(), homeworkResults.end());
  if (homeworkResults.size() % 2 == 0)
  {
    return (float(homeworkResults[(homeworkResults.size() / 2) - 1] + homeworkResults[(homeworkResults.size() / 2)])) / 2 * 0.4 + 0.6 * examResult;
  }
  else
  {
    return homeworkResults[(int)(homeworkResults.size()) / 2] * 0.4 + 0.6 * examResult;
  }
}

float Student::getFinal(float homeworkResult, float examResult)
{
  return 0.4 * homeworkResult + 0.6 * examResult;
}

std::istream& operator >> (std::istream& in, Student& student)
{
  std::cout << "Iveskite studento varda: " << std::endl;
  in >> student.name;
  std::cout << "Iveskite studento pavarde: " << std::endl;
  in >> student.surname;
  std::cout << "Iveskite namu darbu rezultatus, kai baigsite iveskite -1 arba kita neigiama skaiciu: " << std::endl;

  int j = 0;
  int result;
  do
  {
    in >> result;
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
  in >> student.examResult;
  return in;
}

std::istringstream& operator >> (std::istringstream& in, Student& student)
{
  in >> student.name >> student.surname;
  int result;
  while (in >> result)
  {
    in >> result;
    student.homeworkResults.push_back(result);
  }
  if (student.homeworkResults.size() > 0)
  {
    student.examResult = student.homeworkResults.back();
    student.homeworkResults.pop_back();
  }
  return in;
}

std::ofstream& operator << (std::ofstream& out, Student& student)
{
  std::string final;
  std::ostringstream line;
  line << std::left << std::setw(15) << student.name
    << std::setw(17) << student.surname
    << std::fixed << std::setprecision(2) << std::setw(17)
    << student.getFinal((final == "vidurkis") ? student.getAverage() : student.getMedian(), student.examResult);
  out << line.str();
  return out;
}
