#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> x;
int n, k;
bool checkK(ll val) {
  ll sum = 0, subCount = 1;
  for (int i = 0; i < x.size(); i++) {
    if (sum + x[i] <= val) {
      sum += x[i];
    } else {
      subCount++;
      sum = x[i];
    }
    if (subCount > k) {
      return false;
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
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    sumX += x[i];
    mx = max(mx, x[i]);
  }
  ll l = mx, r = sumX;
  while (l < r) {
    ll mid = (l + r) >> 1;
    if (checkK(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}