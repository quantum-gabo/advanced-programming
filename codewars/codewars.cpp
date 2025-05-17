#include <iostream>
#include <vector>
#include <string>

using namespace std;

string slice(string str){
  string result = str.substr(1, str.length() - 2);

  std::cout << "Slice: " << result << std::endl;
  return result;
}

int solution(int number) 
{
  if (number < 0){
    return 0;
  }
  int sum = 0;
  for (int i = 0; i < number; ++i){
    if (i % 3 == 0 || i % 5 == 0){
      sum += i;
    }
  }  
  return sum;
}

int main() {
  //std::string str = "Yellow";
  //std::string sliced_str = slice(str);
  //std::cout << "Sliced string: " << sliced_str << std::endl;
  //return 0;
  int number = 10;
  cout << "Sum of multiples of 3 or 5 below " << number << ": " << solution(number) << std::endl;
}
