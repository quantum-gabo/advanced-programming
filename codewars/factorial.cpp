#include <iostream>

int lastNonZeroDigit(int n) {
  auto removeTrailingZeros = [](int x) {
    while (x % 10 == 0) x /= 10;
    return x;
  };

  int result = 1;
  for (int i = 2; i <= n; ++i) {
    int temp = i;
    while (temp % 2 == 0) temp /= 2;
    while (temp % 5 == 0) temp /= 5;
    result *= temp;
    result = removeTrailingZeros(result);
    result %= 100000;  // Prevent overflow
  }
  return result % 10;
}


int main() {
  long n;
  std::cout << "Enter a number: ";
  std::cin >> n;
  int result = lastNonZeroDigit(n);
  std::cout << "The last non-zero digit of " << n << "! is: " << result << std::endl;
  return 0;
}
