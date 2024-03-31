// 递推
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  dp.resize(n + 1);
  dp[0] = 1;
  for (int sumD = 1; sumD <= n; sumD++) {
    for (int dice = 1; dice <= 6; dice++) {
      // 等于 0 表示本次不投。
      if (sumD - dice >= 0) {
        dp[sumD] += dp[sumD - dice];
        dp[sumD] %= (ll)(1e9 + 7);
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}