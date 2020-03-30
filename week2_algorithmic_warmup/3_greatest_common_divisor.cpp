//#define TESTS_ON

#ifdef TESTS_ON
#include "Test.hpp"
#endif

#include <iostream>
#include <vector>
#include <algorithm>

int gcd_fast(int a, int b)
{
  if(a < b)
    std::swap(a,b);
  int result = 0;
  while (true)
  {
    result = a % b;
    if(result == 0)
    {
      result = b;
      break;
    }
    a = b;
    b = result;
  }
  return result;
}

int main() {

#ifdef TESTS_ON
    Test test;
    test.test();
#else

    int digit1 = 0;
    int digit2 = 0;
    std::cin >> digit1 >> digit2;
    std::cout << gcd_fast(digit1,digit2) << '\n';
#endif
  return 0;
}
