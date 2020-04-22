#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int getCompareNum(int left, int right)
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
    return -1;
  if (left + 1 == right)
  {
    int ret = getCompareNum(array[left], array[right]);
    return ret;
  }
  size_t middle = ((right - left) / 2 + left);
  int leftVal = get_majority_element(array, left, middle - 1);
  int rightVal = get_majority_element(array, middle, right);

  int ret = getCompareNum(leftVal, rightVal);
  return ret;
}

void test1()
{
  std::vector<int> array = {356,2,2,32,2};
  int result = get_majority_element(array, 0, array.size() - 1);

  std::cout << "Result is \"" << result << "\"\n";
}

int main() {
  test1();
//  int n;
//  std::cin >> n;
//  vector<int> array(n);
//  for (size_t i = 0; i < array.size(); ++i) {
//    std::cin >> array[i];
//  }
//  std::cout << (get_majority_element(array, 0, array.size() - 1) == -1 ? 0 : 1) << '\n';

  return 0;
}
