//#define TESTS_ON

#ifdef TESTS_ON
#include "Test.hpp"
#endif

#include <iostream>
#include <vector>
#include <algorithm>

int fast(long long from, long long to)
{
  int result = 1;
  int preResult = 0;
  std::vector<int> modules = {0, 1};
  while (true)
  {
    preResult = (preResult + result) % 10;
    std::swap(preResult, result);

    if(result == 1 && preResult == 0)
    {
      modules.pop_back();
      break;
    }
    modules.emplace_back(result);
  }

  int modulesSize = modules.size();
  int temp1 = from % modulesSize;
  int temp2 = to % modulesSize;
  result = 0;

  if((to - from) < (modulesSize - temp1))
  {
    for(int i = temp1; i < (temp2 + 1); ++i)
      result += modules.at(i);
  }
  else
  {
    for(int i = temp1; i < modulesSize; ++i)
      result += modules.at(i);
    // middle sum value is constant = 280 = (0)
    for(int i = 0; i < (temp2 + 1); ++i)
      result += modules.at(i);
  }
  return result % 10;
}

int main() {

#ifdef TESTS_ON
    Test test;
    test.test();
#else

    long long digit1 = 0;
    long long digit2 = 0;
    std::cin >> digit1 >> digit2;
    std::cout << fast(digit1, digit2) << '\n';
#endif
  return 0;
}
