#include <iomanip>
#include <iostream>

using namespace std;
const double esp = 1e-4;

double calExpressions(double a, double b, double c, double d, double x) {
  return a * x * x * x + b * x * x + c * x + d;
}

double solvingEquations(double a, double b, double c, double d, double left,
                        double right) {
  double valLeft = calExpressions(a, b, c, d, left);
  double valRight = calExpressions(a, b, c, d, right);
  if (valLeft == 0) {
    return left;
  }
  if (valLeft * valRight < 0) {
    while (left + esp < right) {
      double mid = (left + right) / 2;
      double tmp = calExpressions(a, b, c, d, mid);
      if (tmp * valLeft < 0) {
        right = mid;
      } else
        left = mid;
    }
    return left;
  }
  return -200; // 无解
}

int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  int count = 0;
  for (double i = -101; i <= 101; i = i + 0.9) {
    double ans = solvingEquations(a, b, c, d, i, i + 0.9);
    if (ans != -200) {
      cout << fixed << setprecision(2) << ans;
      count++;
      if (count == 3)
        return 0;
      else if (count > 0)
        cout << " ";
    }
  }
  return 0;
}