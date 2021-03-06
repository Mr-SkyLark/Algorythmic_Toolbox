//#define TESTS_ON

#ifdef TESTS_ON
#include "Test.hpp"
#endif

#include <iostream>
#include <vector>
#include <algorithm>

int fibonacci_fast(int n)
{
  if (n <= 1)
      return n;

  long long result = 1;
  long long preResult = 0;
  for(int i = 1; i < n; ++i)
  {
    preResult = (preResult + result) % 10;
    std::swap(preResult, result);
  }

  return result;
}

int main() {

#ifdef TESTS_ON
    Test test;
    test.test();
#else

    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n) << '\n';
#endif
  return 0;
}
