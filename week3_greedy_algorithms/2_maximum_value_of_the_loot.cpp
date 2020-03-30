//#define TESTS_ON

#ifdef TESTS_ON
#include "Test.hpp"
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct Item
{
  Item(int v, int w)
    : value(v)
    , weight(w)
  {
    if(w == 0)
      power = -1.;
    else
      power = static_cast<double>(v) / w;
  }

  int value;
  int weight;
  double power;
};

bool operator < (const Item& left, const Item& right)
{
  if(left.power < 0.)
    return false;
  if(right.power < 0.)
    return true;
  return left.power < right.power;
}

double fast(int w, std::vector<Item>& items)
{
  double result = 0.;
  std::sort(items.begin(), items.end(), std::less<Item>());

  while(w > 0)
  {
    if(items.empty())
      break;
    if(w < items.back().weight)
    {
      result += items.back().power * w;
      w = 0;
    }
    else
    {
      w -= items.back().weight;
      result += static_cast<double>(items.back().value);
    }
    items.pop_back();
  }
  return result;
}

int main() {
#ifdef TESTS_ON
    Test test;
    test.test();
#else
  int n;
  int w;
  int v;
  int capacity;
  std::cin >> n >> capacity;
  std::vector<Item> items;
  items.reserve(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v >> w;
    items.emplace_back(Item(v,w));
  }

  double optimal_value = fast(capacity, items);

  std::cout.precision(15);
  std::cout << optimal_value << std::endl;
#endif
  return 0;
}
