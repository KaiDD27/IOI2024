#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> x;
int n, k;
bool check(ll val) {
  for (ll i = 0, subCount = 1, sum = 0; i < n; i++) {
    if (sum + x[i] <= val) {
      sum += x[i];
    } else {
      subCount++;
      if (subCount > k) {
        return false;
      }
      sum = x[i];
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> k;
  x.resize(n);
  ll sumX = 0, mx = 0;
  for (auto &xi : x) {
    cin >> xi;
    sumX += xi;
    mx = max(mx, xi);
  }
  ll l = mx, r = sumX;
  while (l < r) {
    ll mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}