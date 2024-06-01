#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, a, b;
  cin >> n >> a >> b;
  if (a * 3 <= b * 2)
    if (n % 2 == 0)
      cout << n / 2 * a << endl;
    else
      cout << (n - 3) / 2 * a + b << endl;
  else {
    if (n % 2 == 0)
      cout << n / 6 * b * 2 + n % 6 / 2 * a << endl;
    else
      cout << b + (n - 3) / 6 * b * 2 + (n - 3) % 6 / 2 * a << endl;
  }

  return 0;
}