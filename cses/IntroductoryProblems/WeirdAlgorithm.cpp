#include <iostream>
using namespace std;
#define endl '\n'

int main() {
  long long n;
  cin >> n;
  cout << n;

  while (n != 1) {
    if (n % 2 == 0)
      n /= 2;
    else
      n = 3 * n + 1;
    cout << " " << n;
  }
  cout << endl;
  return 0;
}