#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> x;
bool checkK(ll val, int k) {
  ll sum = 0;
  for (int i = 0; i < x.size(); i++) {
    if (k == 0) {
      return false;
    }
    if (sum + x[i] <= val) {
      sum += x[i];
    } else {
      k--;
      sum = x[i];
    }
  }
  if (k == 0)
    return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, k;
  ll sumX = 0, mx = 0;
  cin >> n >> k;
  x.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    sumX += x[i];
    mx = max(mx, x[i]);
  }
  ll l = mx, r = sumX;
  while (l < r) {
    ll mid = (l + r) >> 1;
    if (checkK(mid, k)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}