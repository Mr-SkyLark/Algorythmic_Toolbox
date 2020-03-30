#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& sq)
{
  std::pair<int,int> maxValuesPair = {0,0};
  std::for_each(sq.begin(), sq.end(), [&](int data)
  {
    if(data >= maxValuesPair.second)
    {
      std::swap(maxValuesPair.second, maxValuesPair.first);
      maxValuesPair.second = data;
    }
    else if(data > maxValuesPair.first)
      maxValuesPair.first = data;
  });

  return static_cast<long long>(maxValuesPair.second) * maxValuesPair.first;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> numbers(n);
  for (int i = 0; i < n; ++i) {
      std::cin >> numbers[i];
  }

  std::cout << MaxPairwiseProduct(numbers) << "\n";
  return 0;
}
