#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <iterator>
#include <random>

struct Student 
{
  int homeworkCount = 0, *homeworkResults, examResult;
  std::string name, surname;
  // Calculate average

  float getFinalMark()
  {
    int totalSum = 0;
    for (int i = 0; i < homeworkCount; i++) 
    {
      totalSum += homeworkResults[i];
    }
    return ((float)totalSum / (homeworkCount) * 0.4) + 0.6 * examResult;
  }
  // Calculate median if it was choosen over average
  float getFinalMark(bool median) 
  {
    for (int i = 1; i < homeworkCount; i++)
    {
      int j = i;
      while(j > 0 && homeworkResults[j] < homeworkResults[j - 1])
      {
        std::swap(homeworkResults[j], homeworkResults[j - 1]);
        j--;
      }
      j = homeworkCount;
    }
    int j = homeworkCount;
    homeworkResults[j] = examResult;
    while(j > 0 && homeworkResults[j] < homeworkResults[j - 1])
    {
      std::swap(homeworkResults[j], homeworkResults[j - 1]);
      j--;
    }
    if (homeworkCount % 2 == 0) 
    {
      return homeworkResults[((homeworkCount + 1) / 2)];
    }
    else 
    {
      return (float(homeworkResults[((homeworkCount + 1) / 2) - 1] + homeworkResults[((homeworkCount + 1) / 2)])) / 2;
    }
  }
};

void readData(int &n, Student *& students) 
{
  std::cout << "Iveskite studentu kieki: " << std::endl;
  std::cin >> n;
  students = new Student[n];
  for (int i = 0; i < n; i++) 
  {
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

    int size = 10;
    if (randomly) 
    {
      size = (std::rand() % 11);
    }

    students[i].homeworkResults = new int[size];
    std::cout << "Iveskite namu darbu rezultatus, kai baigsite iveskite -1 arba kita neigiama skaiciu: " << std::endl;
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
        if (j >= size) {
          if (randomly) 
          {
            break;
          }
          int *oldResults = NULL;
          std::copy(students[i].homeworkResults, students[i].homeworkResults + size - 1, oldResults);
          
          students[i].homeworkResults = new int[size + 10];
          std::copy(oldResults, oldResults + size - 1, students[i].homeworkResults);
          size += 10;
        }
        students[i].homeworkResults[j] = result;
      }
      j++;
    } while (result >= 0);
    students[i].homeworkCount = j + 1;
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

void printResults(int n, Student *students)
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
    std::cout << badInput << std::endl;
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
  Student *students;
  readData(n, students);
  printResults(n, students);
  return 0;
}