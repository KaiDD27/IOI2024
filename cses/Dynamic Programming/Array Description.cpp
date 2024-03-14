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
  dp.resize(2, vector<int>(m + 1));
  int now = 1, old = 0;
  if (x[1] != 0) {
    dp[now][x[1]] = 1; // 只有一种
  } else {
    fill(dp[now].begin(), dp[now].end(), 1);
    dp[now][0] = m; // 这里面存当x[i]==0时，所有的可能性数量之和。
  }

  for (int i = 2; i <= n; i++) {
    swap(now, old);
    fill(dp[now].begin(), dp[now].end(), 0);
    if (x[i - 1] != 0) {
      int prev = dp[old][x[i - 1]];
      if (x[i] != 0) {
        if (abs(x[i] - x[i - 1]) <= 1)
          dp[now][x[i]] = prev;
        else
          dp[now][x[i]] = 0;
      } else if (x[i] == 0) {
        if (x[i - 1] - 1 >= 1) {
          dp[now][x[i - 1] - 1] = prev;
          dp[now][0] += prev;
          dp[now][0] %= modNum;
        }
        if (x[i - 1] + 1 <= m) {
          dp[now][x[i - 1] + 1] = prev;
          dp[now][0] += prev;
          dp[now][0] %= modNum;
        }
        dp[now][x[i - 1]] = prev;
        dp[now][0] += prev;
        dp[now][0] %= modNum;
      }
    } else if (x[i - 1] == 0) {
      if (x[i] != 0) {
        if (x[i] - 1 >= 1) {
          dp[now][x[i]] += dp[old][x[i] - 1];
          dp[now][x[i]] %= modNum;
        }
        if (x[i] + 1 <= m) {
          dp[now][x[i]] += dp[old][x[i] + 1];
          dp[now][x[i]] %= modNum;
        }
        dp[now][x[i]] += dp[old][x[i]];
        dp[now][x[i]] %= modNum;
      } else if (x[i] == 0) {
        for (int j = 1; j <= m; j++) {
          if (j - 1 >= 1) {
            dp[now][j] += dp[old][j - 1];
            dp[now][j] %= modNum;
            dp[now][0] += dp[old][j - 1];
            dp[now][0] %= modNum;
          }
          if (j + 1 <= m) {
            dp[now][j] += dp[old][j + 1];
            dp[now][j] %= modNum;
            dp[now][0] += dp[old][j + 1];
            dp[now][0] %= modNum;
          }
          dp[now][j] += dp[old][j];
          dp[now][j] %= modNum;
          dp[now][0] += dp[old][j];
          dp[now][0] %= modNum;
        }
      }
    }

    if (dp[now][x[i]] == 0) // 剪枝
      break;
  }
  cout << dp[now][x[n]] << endl;
  return 0;
}