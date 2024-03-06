#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> k;
ll n, t;
ll calcProductCount(ll seconds) {
  ll sum = 0;
  for (auto i : k) {
    sum += (seconds / i);
    if (sum >= t)
      break;
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> t;
  k.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  // 只有一台机器生产t 个产品所需的时间应该是上限
  ll l = 1, r = t * k[0];
  while (l < r) {
    ll mid = (l + r) >> 1; // 向下取整
    if (calcProductCount(mid) < t)
      l = mid + 1; // 因middle是向下取整，所以l加1，反之就是r要减1
    else
      r = mid;
  }
  cout << l << endl;
  return 0;
}