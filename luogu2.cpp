#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<ll>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  // 第一维是序列的长度，第二维是序列最后一个数字
  dp.resize(n + 1, vector<ll>(n + 1));
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      ll pre = 0, suffix = 0;
      if (j - 1 == 0)
        pre = 1;
      else
        for (int k = 1; k <= j - 1; k++) {
          pre += dp[j - 1][k];
        }
      if (i - j == 0)
        suffix = 1;
      else
        for (int k = 1; k <= i - j; k++) {
          suffix += dp[i - j][k];
        }
      dp[i][j] = pre * suffix;
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    ans += dp[n][i];
  cout << ans << endl;
  return 0;
}