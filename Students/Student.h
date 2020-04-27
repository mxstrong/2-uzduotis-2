#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

class Student
{
private:
  int examResult = 0;
  std::vector<int> homeworkResults;
  std::string name, surname;
  static std::string medianOrAverage;

  float getAverage();
  float getMedian();
public:
  Student();
  Student(std::string name, std::string surname);
  Student(std::string name, std::string surname, std::vector<int>& homeworkResults, int examResult);

  int getHomeworkResultsCount();
  // Calculate final mark using either median or average of homework results.
  float getFinal();
  std::string getName();
  std::string getSurname();
  int getExamResult();
  static std::string getMedianOrAverage();
  std::vector<int> getHomeworkResults();

  void setName(std::string name);
  void setSurname(std::string surname);
  void setFullName(std::string name, std::string surname);
  void setExamResult(int result);
  static void setMedianOrAverage();
  void addHomeworkResult(int result);

  friend std::istream& operator >> (std::istream& in, Student& student);
  friend std::istringstream& operator >> (std::istringstream& input, Student& student);
  friend std::ofstream& operator << (std::ofstream& out, Student& student);
  friend bool operator == (Student& student1, Student& student2);
  friend bool operator != (Student& student1, Student& student2);
  friend bool operator > (Student& student1, Student& student2);
  friend bool operator >= (Student& student1, Student& student2);
  friend bool operator < (Student& student1, Student& student2);
  friend bool operator <= (Student& student1, Student& student2);
};


