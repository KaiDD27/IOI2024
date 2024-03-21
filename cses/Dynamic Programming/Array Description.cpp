#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const int modNum = 1e9 + 7;
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
  dp.resize(2, vector<int>(m + 2)); // 0和m+1做为墙
  int now = 1, old = 0;
  if (x[1] != 0) {
    dp[now][x[1]] = 1; // 只有一种
  } else {
    fill(dp[now].begin(), dp[now].end(), 1);
    dp[now][0] = 0;     // 墙赋值为 0
    dp[now][m + 1] = 0; // 墙赋值为 0
  }
  // 从第二个数开始到第 n 个数
  for (int i = 2; i <= n; i++) {
    swap(now, old);
    fill(dp[now].begin(), dp[now].end(), 0);
    if (x[i] != 0) {
      dp[now][x[i]] = dp[old][x[i]];
      dp[now][x[i]] %= modNum;

      dp[now][x[i]] += dp[old][x[i] - 1];
      dp[now][x[i]] %= modNum;

      dp[now][x[i]] += dp[old][x[i] + 1];
      dp[now][x[i]] %= modNum;

    } else { // x[i] == 0
      for (int j = 1; j <= m; j++) {
        dp[now][j] = dp[old][j];

        dp[now][j] += dp[old][j - 1];
        dp[now][j] %= modNum;

        dp[now][j] += dp[old][j + 1];
        dp[now][j] %= modNum;
      }
    }
    if (x[i] != 0 && dp[now][x[i]] == 0) // 剪枝,可剪可不剪
      break;
  }

  if (x[n] != 0)
    cout << dp[now][x[n]] << endl;
  else {
    ll sum = 0;
    for (int i = 1; i <= m; i++) {
      sum += dp[now][i];
      sum %= modNum;
    }
    cout << sum << endl;
  }
  return 0;
}
