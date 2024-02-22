#include <iostream>
using namespace std;

long long yVals[100100], xVals[100100];

void calc(long long &y, long long &x) {
  if (x >= y) {
    if (x % 2 == 0)
      cout << (x - 1) * (x - 1) + y << endl;
    else
      cout << x * x - (y - 1) << endl;
  } else {
    if (y % 2 != 0)
      cout << (y - 1) * (y - 1) + x << endl;
    else
      cout << y * y - (x - 1) << endl;
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> yVals[i] >> xVals[i];
  }
  for (int i = 0; i < t; i++) {
    calc(yVals[i], xVals[i]);
  }
  return 0;
}