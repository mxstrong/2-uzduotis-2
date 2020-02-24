#include "Student.h"
#include <algorithm>

float Student::getAverage()
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

float Student::getMedian()
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
