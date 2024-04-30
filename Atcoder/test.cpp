#include <iostream>
#include <string>
#include <vector>

std::string divide(std::string dividend, int divisor, int precision) {
  std::string result;
  int remainder = 0;

  for (char digit : dividend) {
    int current = (digit - '0') + remainder * 10;
    result += (current / divisor) + '0';
    remainder = current % divisor;
  }

  result += '.';

  for (int i = 0; i < precision; i++) {
    remainder *= 10;
    result += (remainder / divisor) + '0';
    remainder %= divisor;
  }

  return result;
}

int main() {
  std::string dividend = "123456789";
  int divisor = 17;
  int precision = 20;

  std::string result = divide(dividend, divisor, precision);

  std::cout << "Result: " << result << std::endl;

  return 0;
}