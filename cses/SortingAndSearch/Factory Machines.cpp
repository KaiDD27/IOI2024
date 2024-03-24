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
  // 其实就是一个lowerBound，大于等于t的第一个取值
  while (l < r) {
    ll mid = (l + r) >> 1; // 向下取整，才能保证不在r=mid死循环
    if (calcProductCount(mid) < t)
      l = mid + 1; // 因middle是向下取整，所以l加1，反之就是r要减1
    else // r不能等于mid-1，因为这样可能会错过唯一相等的值
      r = mid;
  }
  /*
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (calcProductCount(mid) < t)
      l = mid + 1;
    else
      r = mid - 1;
  }*/
  cout << l << endl;
  return 0;
}