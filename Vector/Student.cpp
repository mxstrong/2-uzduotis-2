#include "Student.h"
#include <algorithm>
#include <numeric>

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
