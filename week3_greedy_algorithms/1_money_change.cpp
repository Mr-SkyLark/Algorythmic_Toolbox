//#define TESTS_ON

#ifdef TESTS_ON
#include "Test.hpp"
#endif

#include <iostream>
#include <vector>
#include <algorithm>

int fast(int n)
{
  int result = n / 10;
  n -= result * 10;

  while(n > 0)
  {
    if(n >= 5)
      n -= 5;
    else
      n -= 1;
    ++result;
  }
  return result;

}

int main() {

#ifdef TESTS_ON
    Test test;
    test.test();
#else

    int digit1 = 0;
    std::cin >> digit1;
    std::cout << fast(digit1) << '\n';
#endif
  return 0;
}
