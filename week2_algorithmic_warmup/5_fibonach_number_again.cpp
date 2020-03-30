//#define TESTS_ON

#ifdef TESTS_ON
#include "Test.hpp"
#endif

#include <iostream>
#include <vector>
#include <algorithm>

long long fast(long long n, long long m)
{
  if (n <= 1)
      return n;

  long long result = 1;
  long long preResult = 0;
  std::vector<long long> modules = {0, 1};
  while (true)
  {
    preResult = (preResult + result) % m;
    std::swap(preResult, result);

    if(result == 1 && preResult == 0)
    {
      break;
    }
    modules.emplace_back(result);
  }
  return modules.at(n % (modules.size() - 1));
}

int main() {

#ifdef TESTS_ON
    Test test;
    test.test();
#else

    long long digit1 = 0;
    long long digit2 = 0;
    std::cin >> digit1 >> digit2;
    std::cout << fast(digit1,digit2) << '\n';
#endif
  return 0;
}
