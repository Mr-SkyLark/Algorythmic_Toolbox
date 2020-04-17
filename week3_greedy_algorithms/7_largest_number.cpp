#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool stringGreaterCustom (const std::string& left, const std::string& right)
{
  auto rightSize = right.size();
  auto leftSize = left.size();

  bool isLeftGreater = false;
  bool isUniqueCase = false;

  size_t equalCounter = 0;
  // calculate
  for(size_t i = 0; i < leftSize || i < rightSize; ++i)
  {
    char checkingLeft;
    char checkingRight;
    if(i >= leftSize)
    {
      checkingLeft = left.front();
      checkingRight = right[i];
    }
    else if(i >= rightSize)
    {
      checkingLeft = left[i];
      checkingRight = right.front();
    }
    else
    {
      checkingLeft = left[i];
      checkingRight = right[i];
    }
    if(checkingLeft == checkingRight)
    {
      ++equalCounter;
      continue;
    }
    isLeftGreater = checkingLeft > checkingRight;
    break;
  }

  if(leftSize != rightSize && equalCounter == std::max(leftSize,rightSize))
    isUniqueCase = true;

  if(isUniqueCase)
  {
    if(leftSize < rightSize)
    {
      isLeftGreater = left.front() < right[leftSize - 1];
    }
    else
    {
      isLeftGreater = right.front() > left[rightSize - 1];
    }
  }
  return isLeftGreater;
}

string largest_number(vector<std::string>& numbers)
{
  std::sort(numbers.begin(), numbers.end(), stringGreaterCustom);
  std::stringstream ret;
  for (size_t i = 0; i < numbers.size(); i++)
  {
    ret << numbers[i];
  }
  return ret.str();
}

void testGreaterFunction()
{
  std::string left;
  std::string right;

  left = "9";
  right = "9";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | False" << "\n";

  left = "9";
  right = "10";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | True" << "\n";

  left = "3";
  right = "332";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | True" << "\n";

  left = "332";
  right = "3";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | False" << "\n";

  left = "3";
  right = "334";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | False" << "\n";

  left = "334";
  right = "3";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | True" << "\n";

  left = "33";
  right = "332";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | True" << "\n";

  left = "332";
  right = "33";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | False" << "\n";

  left = "33";
  right = "334";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | False" << "\n";

  left = "334";
  right = "33";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | True" << "\n";

  left = "43";
  right = "433";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | True" << "\n";

  left = "433";
  right = "43";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | False" << "\n";

  left = "43";
  right = "434";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | False" << "\n";

  left = "434";
  right = "43";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | True" << "\n";

  left = "34";
  right = "343";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | True" << "\n";

  left = "343";
  right = "34";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | False" << "\n";

  left = "33";
  right = "333";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | False" << "\n";

  left = "333";
  right = "3";
  std::cout << left << " > " << right << " = " <<
                (stringGreaterCustom(left, right) ? "True" : "False") << " | False" << "\n";
}

void testRundom()
{
  vector<std::string> testData = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
  vector<std::string> numbers(100);
  for (int i = 0; i < 100; ++i)
  {
    numbers[i] = testData[std::rand() % 10];
  }
  std::cout << "Result: " << largest_number(numbers) << "\n";
}

int main() {
  size_t count;
  std::cin >> count;
  vector<std::string> numbers(count);
  for (size_t i = 0; i < numbers.size(); i++) {
    std::cin >> numbers[i];
  }

  std::cout << largest_number(numbers);
//  testRundom();
//  testGreaterFunction();
}
