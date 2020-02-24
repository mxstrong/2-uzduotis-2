#pragma once
#include <vector>
#include <string>

struct Student
{
  int examResult = 0;
  std::vector<int> homeworkResults;
  std::string name, surname;
  // Calculate average
  float getAverage();
  
  // Calculate median if it was choosen over average
  float getMedian();
};
