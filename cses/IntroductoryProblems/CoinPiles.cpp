#include <cstdlib>
#include <iostream>
#include <ostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int a, b;
    cin >> a >> b;
    if ((a + b) % 3 == 0 && abs(a - b) <= min(a, b))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}