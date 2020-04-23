#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::vector;

int otherImpl(const vector<int> &array)
{
  size_t size = array.size();
  std::map<int, size_t> countMap;
  for(int value : array)
  {
    ++countMap[value];
  }
  auto it = std::find_if(countMap.begin(),countMap.end(),
               [&](const std::pair<int, size_t>& pair)
  {return pair.second > (size / 2);}
  );
  if(it == countMap.end())
    return -1;
  return it->first;
}

int getMajoreNum(int left, int right)
{
  if(left == right)
    return left;
  if(left < 0)
    return right;
  if(right < 0)
    return left;
  return -1;
}

int get_majority_element(const vector<int> &array, size_t left, size_t right) {
  if (left == right)
    return array[left];
  if (left + 1 == right)
  {
    int ret = (array[left] == array[right]) ? array[left] : -1;
    return ret;
  }
  size_t middle = ((right - left) / 2 + left);
  int leftValue = get_majority_element(array, left, middle - 1);
  int rightValue = get_majority_element(array, middle, right);

  // For left
  size_t valueCount = 0;
  for (size_t i = left; i <= right; ++i)
  {
    if(array[i] == leftValue)
      ++valueCount;
  }
  if(valueCount < (1 + (right - left + 1) / 2) )
    leftValue = -1;

  // For right
  valueCount = 0;
  for (size_t i = left; i <= right; ++i)
  {
    if(array[i] == rightValue)
      ++valueCount;
  }
  if(valueCount < (1 + (right - left + 1) / 2) )
    rightValue = -1;

  int ret = getMajoreNum(leftValue, rightValue);
  return ret;
}

void test1()
{
  std::vector<int> array = {356,2,32,2,2};
  int result = get_majority_element(array, 0, array.size() - 1);
  int otherResult = otherImpl(array);
  std::cout << "Result is: " << otherResult << "|" << result << "\"\n";

  array = {356,2,2,32,2};
  result = get_majority_element(array, 0, array.size() - 1);
  otherResult = otherImpl(array);
  std::cout << "Result is: " << otherResult << "|" << result << "\"\n";

  array = {356,2,2,2,32};
  result = get_majority_element(array, 0, array.size() - 1);
  otherResult = otherImpl(array);
  std::cout << "Result is: " << otherResult << "|" << result << "\"\n";

  array = {2,2,2,2,2};
  result = get_majority_element(array, 0, array.size() - 1);
  otherResult = otherImpl(array);
  std::cout << "Result is: " << otherResult << "|" << result << "\"\n";

  array = {2,2,2,23,32};
  result = get_majority_element(array, 0, array.size() - 1);
  otherResult = otherImpl(array);
  std::cout << "Result is: " << otherResult << "|" << result << "\"\n";

  array = {356,2,2,2,2};
  result = get_majority_element(array, 0, array.size() - 1);
  otherResult = otherImpl(array);
  std::cout << "Result is: " << otherResult << "|" << result << "\"\n";

  array = {2};
  result = get_majority_element(array, 0, array.size() - 1);
  otherResult = otherImpl(array);
  std::cout << "Result is: " << otherResult << "|" << result << "\"\n";
  array = {2,2};
  result = get_majority_element(array, 0, array.size() - 1);
  otherResult = otherImpl(array);
  std::cout << "Result is: " << otherResult << "|" << result << "\"\n";
  array = {3,2};
  result = get_majority_element(array, 0, array.size() - 1);
  otherResult = otherImpl(array);
  std::cout << "Result is: " << otherResult << "|" << result << "\"\n";

  array.clear();
  for (size_t i = 0; i < 100000; ++i)
  {
    array.emplace_back(std::rand() % 100000);
  }
  result = get_majority_element(array, 0, array.size() - 1);
  otherResult = otherImpl(array);
  std::cout << "Result is: " << otherResult << "|" << result << "\"\n";

  array.clear();
  for (size_t i = 0; i < 100000; ++i)
  {
    array.emplace_back(std::rand() % 2);
  }
  result = get_majority_element(array, 0, array.size() - 1);
  otherResult = otherImpl(array);
  std::cout << "Result is: " << otherResult << "|" << result << "\"\n";
}

int main() {
  //test1();
  int n;
  std::cin >> n;
  vector<int> array(n);
  for (size_t i = 0; i < array.size(); ++i) {
    std::cin >> array[i];
  }
  std::cout << (get_majority_element(array, 0, array.size() - 1) == -1 ? 0 : 1) << '\n';

  return 0;
}
