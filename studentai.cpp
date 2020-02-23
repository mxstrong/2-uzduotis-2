#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <iterator>
#include <random>
#include <vector>
#include <filesystem>
#include <chrono>

struct Student 
{
  int examResult = 0;
  std::vector<int> homeworkResults;
  std::string name, surname;
  // Calculate average

  float getAverage()
  {
    int totalSum = 0;
    for (auto result : homeworkResults) 
    {
      totalSum += result;
    }
    if (homeworkResults.size() == 0)
    {
      return 0.6 * examResult;
    }
    return ((float)totalSum / (homeworkResults.size()) * 0.4) + 0.6 * examResult;
  }
  // Calculate median if it was choosen over average
  float getMedian() 
  {
    if (homeworkResults.size() == 0)
    {
      return 0;
    }
    std::sort(homeworkResults.begin(), homeworkResults.end());
    if (homeworkResults.size() % 2 == 0) 
    {
      return (float(homeworkResults[(homeworkResults.size() / 2) - 1] + homeworkResults[(homeworkResults.size() / 2)])) / 2;
    }
    else 
    {
      return homeworkResults[(int)(homeworkResults.size()) / 2];
    }
  }
};

int generateRandomInt(int lowLimit, int highLimit)
{
  using clock = std::chrono::high_resolution_clock;
  std::mt19937 mt(static_cast<long unsigned int>(clock::now().time_since_epoch().count()));
  std::uniform_int_distribution<int> dist(lowLimit, highLimit);
  return dist(mt);
}

int calculateHomeworkCount(const std::string &input)
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
void readDataFromInput(int &n, std::vector<Student>& students) 
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

      if (result >= 0) {
        students[i].homeworkResults.push_back(result);
      }
      j++;
    } while (result >= 0);
 
     std::cout << "Iveskite egzamino rezultata: " << std::endl;
     std::cin >> students[i].examResult;
  }
}

// Read data from file
void readDataFromFile(std::string fileName, int &n, std::vector<Student>& students)
{
  std::string input;
  std::ifstream f(fileName.c_str());
  std::getline(f, input);
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
  std::vector<std::string> names { "Vardenis", "Vardas", "Vardukas", "Vardiklis", "Vardonis", "Vardanas", "Vardauskas" };
  std::vector<std::string> surnames { "Pavardenis", "Pavarde", "Pavardukas", "Pavardiklis", "Pavardonis", "Pavardanas", "Pavardauskas" };
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

bool isFirst(Student first, Student second)
{
  if (first.name < second.name)
  {
    return true;
  }
  else if (second.name < first.name)
  {
    return false;
  }
  else
  {
    return (first.surname < second.surname) ? true : false;
  }
}

void printResultsToFile(int n, std::vector<Student> students)
{
  std::ofstream res("rezultatai.txt");
  res << std::left 
      << std::setw(15) << "Vardas" 
      << std::setw(17) << "Pavarde" 
      << std::setw(17) << "Galutinis (Vid.) "
      << std::setw(16) << "Galutinis (Med.)"
      << std::endl;
  for (int i = 0; i < 65; i++) 
  {
    res << '-';
  }
  res << std::endl;
  std::sort(students.begin(), students.end(), isFirst);
  for (Student student : students)
  {
    res << std::setw(15) << student.name 
        << std::setw(17) << student.surname
        << std::fixed << std::setprecision(2) << std::setw(17) << student.getAverage()
        << std::setw(16) << student.getMedian()
        << std::endl;
  }
  res.close();
}

int main() 
{
  std::srand(time(NULL));
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
      std::string fileName;
      std::cout << "Iveskite failo varda: " << std::endl;
      std::cin >> fileName;
      if(std::filesystem::exists(fileName))
      {
        fileExists = true;
        readDataFromFile(fileName, n, students);
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