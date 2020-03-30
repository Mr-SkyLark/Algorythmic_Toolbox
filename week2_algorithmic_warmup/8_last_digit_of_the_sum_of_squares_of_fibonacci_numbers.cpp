//#define TESTS_ON

#ifdef TESTS_ON
#include "Test.hpp"
#endif

#include <iostream>
#include <vector>
#include <algorithm>

int fast(long long n)
{
  if (n <= 1)
        return n;
      
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
  int temp1 = modules.at(n % modulesSize);
  int temp2 = modules.at((n-1) % modulesSize);

  return result = ((temp1 + temp2) * temp1) % 10;

}

int main() {

#ifdef TESTS_ON
    Test test;
    test.test();
#else

    long long digit1 = 0;
    std::cin >> digit1;
    std::cout << fast(digit1) << '\n';
#endif
  return 0;
}
