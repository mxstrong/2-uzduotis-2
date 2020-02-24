#include "Random.h"
#include <chrono>
#include <random>

int generateRandomInt(int lowLimit, int highLimit)
{
  using clock = std::chrono::high_resolution_clock;
  std::mt19937 mt(static_cast<long unsigned int>(clock::now().time_since_epoch().count()));
  std::uniform_int_distribution<int> dist(lowLimit, highLimit);
  return dist(mt);
}