#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll a, m, l, r;
  cin >> a >> m >> l >> r;
  if (abs(l - a) % m == 0 || abs(r - a) % m == 0) {
    cout << (r - l) / m + 1 << endl;
    return 0;
  }
  if (a > l) {
    l = l - (m - (a - l) % m);
    cout << (r - l) / m << endl;

  } else {
    l = l - (l - a) % m;
    cout << (r - l) / m << endl;
  }

  return 0;
}