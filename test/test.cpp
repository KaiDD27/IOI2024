#include <functional>
#include <iostream>
#include <vector>

using namespace std;

function<double(double, double)> add = [](double x, double y) { return x + y; };
function<double(double, double)> subtract = [](double x, double y) {
  return x - y;
};
function<double(double, double)> multiply = [](double x, double y) {
  return x * y;
};
function<double(double, double)> divide = [](double x, double y) {
  return x / y;
};

double calculate(vector<function<double(double, double)>> operations,
                 vector<double> numbers) {
  double result = numbers[0];
  for (size_t i = 0; i < operations.size(); ++i) {
    result = operations[i](result, numbers[i + 1]);
  }
  return result;
}

int main() {
  vector<function<double(double, double)>> operations = {add, subtract,
                                                         multiply};
  vector<double> numbers = {1.0, 2.0, 3.0, 4.0};
  double result = calculate(operations, numbers);
  cout << "Result: " << result << endl;
  return 0;
}