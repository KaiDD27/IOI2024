#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n;
  cin >> n;
  ll minCost = 0;
  for (int i = 0; i < n; i++) {
    ll w, a, x, b, y;
    cin >> w >> a >> x >> b >> y;
    if (x <= y) {
      minCost += (min(w, a) * x + max(w - a, 0ll) * y);
    } else {
      minCost += (min(w, b) * y + max(w - b, 0ll) * x);
    }
  }
  cout << minCost << endl;
  return 0;
}