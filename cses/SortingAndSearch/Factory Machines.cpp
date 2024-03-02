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
  ll l = 1, r = 1e18; // long long最大也就是 10 的 18 次方多，不到 10 的 19 次方
  while (l < r) {
    ll middle = (l + r) >> 1; // 向下取整
    if (calcProductCount(middle) < t)
      l = middle + 1; // 因middle是向下取整，所以l加1，反之就是r要减1
    else
      r = middle;
  }
  cout << l << endl;
  return 0;
}