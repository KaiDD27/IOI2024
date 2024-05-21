#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <random>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, c;
map<ll, ll> mpH;
map<ll, ll> mpHSuffix;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> c;
  // 统计相同高度的树的数量
  for (int i = 0; i < n; i++) {
    ll h = 0;
    cin >> h;
    mpH[h]++;
  }

  // 求后缀和
  ll suffixSum = 0;
  for (auto it = mpH.rbegin(); it != mpH.rend(); it++) {
    suffixSum += it->second;
    mpHSuffix[it->first] = suffixSum;
  }

  // 从 1 开始到最高的树，看看每一层是否可以获得利润
  ll ans = 0;
  ll hi = 1;
  while (hi <= mpHSuffix.rbegin()->first) {
    auto it = mpHSuffix.lower_bound(hi);
    ll profitH = (c / 5) / it->second + 1;
    if (it->first >= profitH) {
      // 注意取当前高度和能获得利润的高度中的较大值
      ans += (it->first - max(profitH, hi) + 1);
    }
    // 从更高一层开始
    hi = it->first + 1;
  }
  cout << ans << endl;
  return 0;
}