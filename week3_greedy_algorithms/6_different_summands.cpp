#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n)
{
  vector<int> summands;
  for(int i = 1; n > 0; ++i)
  {
    n -= i;
    if(n < (i + 1))
    {
      i += n;
      n = 0;
    }
    summands.emplace_back(i);
  }
  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
