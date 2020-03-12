#pragma once
#include <deque>
#include <string>

struct Student
{
  int examResult = 0;
  std::deque<int> homeworkResults;
  std::string name, surname;
  float getAverage();
  float getMedian();

  // Calculate final mark using either median or average of homework results as first parameter.
  float getFinal(float homeworkResult, float examResult);
};
