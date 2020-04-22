#include <iostream>
#include <vector>

void bynarySearch(size_t maxNumber, std::vector<size_t>& resultList)
{
  size_t counter= maxNumber / 2;
  if(maxNumber % 2 == 1)
    counter += 1;
  resultList.emplace_back(counter);
  for (size_t i = 0; counter != 1; ++i)
  {
    counter >>= 1;
    resultList.emplace_back(resultList[i] + counter);
  }
}

int main()
{
  size_t maxNumber;
  std::cin >> maxNumber;
//  maxNumber = 3;
  std::vector<size_t> resultList;
  bynarySearch(maxNumber, resultList);

  std::cout << "size: " << resultList.size() << "\n";
  for(auto result : resultList)
  {
    std::cout << result << "\n";
  }
  return 0;
}
