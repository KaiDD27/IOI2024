#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> digitalHurt(10);
// 用了乘法或者不用乘法的最小伤害
vector<ll> numMultipHurt;
ll getHurt(ll x) {
  ll result = 0;
  while (x != 0) {
    result += digitalHurt[x % 10];
    x /= 10;
  }
  return result;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, addHurt, multipHurt, equalHurt;
  cin >> n;
  numMultipHurt.resize(n + 1);
  for (auto &ni : digitalHurt)
    cin >> ni;
  cin >> addHurt >> multipHurt >> equalHurt;
  for (ll i = 1; i <= n; i++) {
    // 初始化为不用乘法
    ll minHurt = getHurt(i);
    ll sqrtNum = sqrt(i);
    for (ll j = 1; j <= sqrtNum; j++) {
      if (i % j == 0) {
        minHurt = min(minHurt, getHurt(j) + getHurt(i / j) + multipHurt);
      }
    }
    numMultipHurt[i] = minHurt;
  }
  ll ans = numMultipHurt[n];
  for (int i = 1; i < n; i++) {
    ans = min(ans, numMultipHurt[i] + getHurt(n - i) + addHurt);
  }
  cout << ans + equalHurt << endl;

  return 0;
}