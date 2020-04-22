#include <iostream>
#include <cassert>
#include <vector>

#include<algorithm>

using std::vector;

int binary_search(const vector<int> &array, int x)
{
  int left = 0;
  int right = static_cast<int>(array.size()) - 1;
  int middle = 0;
  bool isFound = false;
  while(right >= left)
  {
    middle = ((right - left) / 2) + left;
    if(array[static_cast<size_t>(middle)] == x)
    {
      isFound = true;
      break;
    }
    if(array[static_cast<size_t>(middle)] < x)
      left = middle + 1;
    else
      right = middle - 1;
  }

  return isFound ? middle : -1;
}

int std_search(const vector<int> &array, int x)
{
  auto lowerIt = std::lower_bound(array.cbegin(), array.cend(), x);
  auto upperIt = std::upper_bound(array.cbegin(), array.cend(), x);
  if(lowerIt == upperIt)
    return -1;
  else
    return std::distance(array.cbegin(), lowerIt);
}

void test1()
{
  std::vector<int> sortedArray;
  sortedArray = {11, 41, 71};
  std::cout << "Find 11: " << std_search(sortedArray, 11) <<
               "|" <<  binary_search(sortedArray, 11) << "\n";
  std::cout << "Find 41: " << std_search(sortedArray, 41) <<
               "|" << binary_search(sortedArray, 41) << "\n";
  std::cout << "Find 71: " << std_search(sortedArray, 71) <<
               "|" << binary_search(sortedArray, 71) << "\n";
  std::cout << "Find 1: " << std_search(sortedArray, 1) <<
               "|" << binary_search(sortedArray, 1) << "\n";
  std::cout << "Find 21: " << std_search(sortedArray, 21) <<
               "|" << binary_search(sortedArray, 21) << "\n";
  std::cout << "Find 51: " << std_search(sortedArray, 51) <<
               "|" << binary_search(sortedArray, 51) << "\n";
  std::cout << "Find 81: " << std_search(sortedArray, 81) <<
               "|" << binary_search(sortedArray, 81) << "\n";
}

void test2()
{
  vector<int> numbers(100);
  for (int i = 0; i < 100; ++i)
  {
    numbers[i] = std::rand() % 100;
  }
  std::sort(numbers.begin(), numbers.end());

  bool isOk = true;
  for(int i = 0; i < 102; ++i)
  {
    int my = binary_search(numbers, i);
    int std = std_search(numbers,i);
    if(std != my)
    {
      std::cout << "--- Fail. i=" << i << "; " << std <<
                   "|" << my << "\n";
      isOk = false;
    }
  }
  std::cout << "Result: " << (isOk ? "Ok" : "False") << "\n";
}

int main()
{
//  test1();
//  test2();
  size_t n;
  std::cin >> n;
  vector<int> sortedArray(n);
  for (size_t i = 0; i < sortedArray.size(); i++) {
    std::cin >> sortedArray[i];
  }
  size_t m;
  std::cin >> m;
  vector<int> findNumbers(m);
  for (size_t i = 0; i < m; ++i) {
    std::cin >> findNumbers[i];
  }
  for (size_t i = 0; i < m; ++i) {
    std::cout << binary_search(sortedArray, findNumbers[i]) << ' ';
  }

  return 0;
}
