// 递推
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const int MOD = 1e9 + 7;
vector<int> x;
vector<vector<int>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  x.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> x[i];
  dp.resize(n + 1, vector<int>(m + 2)); // 0和m+1做为墙

  if (x[1] != 0) {
    dp[1][x[1]] = 1; // 只有一种
  } else {
    fill(dp[1].begin(), dp[1].end(), 1);
    dp[1][0] = 0;     // 墙赋值为 0
    dp[1][m + 1] = 0; // 墙赋值为 0
  }
  // 从第二个数开始到第 n 个数
  for (int i = 2; i <= n; i++) {
    if (x[i] != 0) {
      dp[i][x[i]] = dp[i - 1][x[i]];

      dp[i][x[i]] += dp[i - 1][x[i] - 1];
      dp[i][x[i]] %= MOD;

      dp[i][x[i]] += dp[i - 1][x[i] + 1];
      dp[i][x[i]] %= MOD;

    } else { // x[i] == 0
      for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i - 1][j];

        dp[i][j] += dp[i - 1][j - 1];
        dp[i][j] %= MOD;

        dp[i][j] += dp[i - 1][j + 1];
        dp[i][j] %= MOD;
      }
    }
    if (x[i] != 0 && dp[i][x[i]] == 0) // 剪枝,可剪可不剪
      break;
  }

  if (x[n] != 0)
    cout << dp[n][x[n]] << endl;
  else {
    ll sum = 0;
    for (int i = 1; i <= m; i++) {
      sum += dp[n][i];
      sum %= MOD;
    }
    cout << sum << endl;
  }
  return 0;
}
