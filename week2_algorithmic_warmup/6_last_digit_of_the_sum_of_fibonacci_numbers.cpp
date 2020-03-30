//#define TESTS_ON

#ifdef TESTS_ON
#include "Test.hpp"
#endif

#include <iostream>
#include <vector>
#include <algorithm>

int fast(long long n)
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
  long long temp = (n+1) / modules.size();
  if(temp)
  {
    preResult = 0;
    std::for_each(modules.begin(), modules.end(), [&] (int i) {
        preResult += i;
    });
    preResult = ((preResult % 10) * (temp % 10)) % 10;
  }

  temp = (n+1) % modules.size();
  result = 0;
  for(int i = 0; i < temp; ++i)
    result += modules.at(i);

  return (result + preResult) % 10;
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
