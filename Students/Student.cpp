#include "Student.h"
#include <algorithm>
#include <numeric>
#include <iomanip>

std::string Student::medianOrAverage = "";

Student::Student()
{
  name = "";
  surname = "";
}

Student::Student(std::string name, std::string surname)
{
  this->name = name;
  this->surname = surname;
}

Student::Student(std::string name, std::string surname, std::vector<int>& homeworkResults, int examResult)
{
  this->name = name;
  this->surname = surname;
  this->homeworkResults = homeworkResults;
  this->examResult = examResult;
}

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

float Student::getFinal()
{
  if (Student::medianOrAverage == "vidurkis") 
  {
    return 0.4 * this->getAverage() + 0.6 * examResult;
  }
  else 
  {
    return 0.4 * this->getMedian() + 0.6 * examResult;
  }
}

int Student::getHomeworkResultsCount()
{
  return homeworkResults.size();
}

std::string Student::getName()
{
  return name;
}

std::string Student::getSurname()
{
  return surname;
}

int Student::getExamResult()
{
  return examResult;
}

std::string Student::getMedianOrAverage()
{
  return Student::medianOrAverage;
}

std::vector<int> Student::getHomeworkResults()
{
  return homeworkResults;
}

void Student::setName(std::string name)
{
  this->name = name;
}
void Student::setSurname(std::string surname)
{
  this->surname = surname;
}

void Student::setFullName(std::string name, std::string surname)
{
  this->name = name;
  this->surname = surname;
}

void Student::addHomeworkResult(int result) 
{
  homeworkResults.push_back(result);
}

void Student::setExamResult(int result)
{
  examResult = result;
}

void Student::setMedianOrAverage()
{
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
  Student::medianOrAverage = final;
}

std::istream& operator >> (std::istream& in, Student& student)
{
  std::string name;
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
    << student.getFinal();
  out << line.str();
  return out;
}
