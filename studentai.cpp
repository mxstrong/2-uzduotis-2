#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <iterator>
#include <random>
#include <vector>

struct Student 
{
  int examResult;
  std::vector<int> homeworkResults;
  std::string name, surname;
  // Calculate average

  float getFinalMark()
  {
    int totalSum = 0;
    for (auto result : homeworkResults) 
    {
      totalSum += result;
    }
    return ((float)totalSum / (homeworkResults.size()) * 0.4) + 0.6 * examResult;
  }
  // Calculate median if it was choosen over average
  float getFinalMark(bool median) 
  {
    for (int i = 1; i < homeworkResults.size(); i++)
    {
      int j = i;
      while(j > 0 && homeworkResults[j] < homeworkResults[j - 1])
      {
        std::swap(homeworkResults[j], homeworkResults[j - 1]);
        j--;
      }
      j = homeworkResults.size();
    }
    homeworkResults.push_back(examResult);
    int j = homeworkResults.size() - 1;
    while(j > 0 && homeworkResults[j] < homeworkResults[j - 1])
    {
      std::swap(homeworkResults[j], homeworkResults[j - 1]);
      j--;
    }
    if (homeworkResults.size() % 2 == 0) 
    {
      return (float(homeworkResults[(homeworkResults.size() / 2) - 1] + homeworkResults[(homeworkResults.size() / 2)])) / 2;
    }
    else 
    {
      return homeworkResults[homeworkResults.size() / 2];
    }
  }
};
// Read data from console input
void readData(int &n, std::vector<Student>& students) 
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
    bool randomly = false;
    std::string input = "";
    std::cout << "Generuoti balus atsitiktinai? (Taip arba Ne)" << std::endl;
    do {
      std::cin >> input;
      if (input == "Taip") 
      {
        randomly = true;
      }
      else if (input != "Ne")
      {
        std::cout << "Iveskite Taip arba Ne" << std::endl;
      }
    } while (!(input == "Taip" || input == "Ne"));

    int size = 0;
    if (randomly) 
    {
      size = (std::rand() % 11);
    }
    else 
    {
      std::cout << "Iveskite namu darbu rezultatus, kai baigsite iveskite -1 arba kita neigiama skaiciu: " << std::endl;
    }
    int j = 0;
    int result;
    do
    {
      if (randomly) 
      {
        result = std::rand() % 11;
        std::cout << result << std::endl;
      }
      else 
      {
        std::cin >> result;
      }
      if (result >= 0) {
        students[i].homeworkResults.push_back(result);
      }
      j++;
    } while (result >= 0 && !(randomly && j >= size));
    if (randomly) 
    {
      students[i].examResult = std::rand() % 11;
      std::cout << "Egzamino rezultatas: " << students[i].examResult << std::endl;
    }
    else 
    {
      std::cout << "Iveskite egzamino rezultata: " << std::endl;
      std::cin >> students[i].examResult;
    }
  }
}

void printResults(int n, std::vector<Student> students)
{
  std::string final = "";
  bool badInput = false;
  do 
  {
    if (badInput) {
      std::cout << "Pasirinkote negalima pasirinkima. Galimi pasirinkimai: vidurkis, mediana" << std::endl;
    }
    std::cout << "Pasirinkite galutini bala (vidurkis ar mediana)" << std::endl;
    std::cin >> final;
    badInput = !(final.compare("vidurkis") == 0 || final.compare("mediana") == 0);
  } while (badInput);
  std::cout << std::left 
            << std::setw(12) << "Vardas" 
            << std::setw(13) << "Pavarde" 
            << std::setw(25) << ((final == "vidurkis") ? "Galutinis (Vid.)" : "Galutinis (Med.)")
            << std::endl;
  for (int i = 0; i < 50; i++) 
  {
    std::cout << '-';
  }
  std::cout << std::endl;
  for (int i = 0; i < n; i++)
  {
    float finalMark = (final == "vidurkis") ? students[i].getFinalMark() : students[i].getFinalMark(true);
    std::cout << std::setw(12) << students[i].name 
              << std::setw(13) << students[i].surname
              << std::fixed << std::setprecision(2) << std::setw(25) << finalMark
              << std:: endl;
  }
}

int main() 
{
  std::srand(time(NULL));
  int n;
  std::vector<Student> students;
  readData(n, students);
  printResults(n, students);
  return 0;
}