//#define TESTS_ON

#ifdef TESTS_ON
#include "Test.hpp"
#endif

#include <iostream>
#include <list>
#include <algorithm>
#include <functional>

int fast(int distance, int partOnFuel, std::list<int>& fuelStations)
{

  if(distance <= partOnFuel)
    return 0;

  fuelStations.emplace_front(0);
  fuelStations.emplace_back(distance);

  int result = 0;
  std::list<int>::const_iterator it = fuelStations.begin();
  std::list<int>::const_iterator stop = fuelStations.begin();
  std::list<int>::const_iterator endIt = fuelStations.end();

  bool lucky = false;
  for(;it != endIt; ++it)
  {
    lucky = false;
    int diff = *it - *stop;

    if(diff == partOnFuel)
    {
      lucky = true;
      stop = it;
      ++result;
    }
    if(diff > partOnFuel)
    {
      --it;
      if(it == stop)
        return -1;
      stop = it;
      ++result;
    }

  }
  if(lucky)
  {
    --result;
  }
  return result;
}

int main() {
#ifdef TESTS_ON
    Test test;
    test.test();
#else
  int distance;
  int partOnFuel;
  int count;
  std::cin >> distance >> partOnFuel >> count;
  std::list<int> fuelStations;
  for (int i = 0; i < count; i++)
  {
    int fuelStation;
    std::cin >> fuelStation;
    fuelStations.emplace_back(fuelStation);
  }

  std::cout << fast(distance, partOnFuel, fuelStations) << std::endl;
#endif
  return 0;
}
