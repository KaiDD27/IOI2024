// 记忆化搜索
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<vector<ll>> dp;
vector<ll> x;
vector<ll> preSum;
ll dfs(int i, int j) {
  if (i == j)
    return x[i];
  if (dp[i][j] != LLONG_MIN)
    return dp[i][j];
  dp[i][j] = max(x[i] + preSum[j] - preSum[i] - dfs(i + 1, j),
                 x[j] + preSum[j - 1] - preSum[i - 1] - dfs(i, j - 1));
  return dp[i][j];
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  x.resize(n + 1);
  preSum.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    preSum[i] = preSum[i - 1] + x[i];
  }
  dp.resize(n + 1, vector<ll>(n + 1, LLONG_MIN));
  cout << dfs(1, n) << endl;
  return 0;
}