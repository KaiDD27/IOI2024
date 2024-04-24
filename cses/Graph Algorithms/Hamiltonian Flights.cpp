#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> inAdj;
vector<array<ll, 20 + 1>> dp;
const ll MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together

  int n, m;
  cin >> n >> m;
  inAdj.resize(n + 1);
  dp.resize(1 << n, array<ll, 20 + 1>());
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    inAdj[b].push_back(a);
  }
  // dp[1]中终点是 1，有一条路径，终点位其他的都为 0
  dp[1][1] = 1;
  // dp[1]已经处理完了，从 dp[2]开始就好
  for (int i = 2; i < 1 << n; i++) {
    // 剪枝必要，不包含 第 1 位为 1 的前置都是没有意义的
    if ((i & 1) == 0)
      continue;
    // 剪枝非必要，不是全 1，且包含 n 位为 1 的都没有意义
    if (i != ((1 << n) - 1) && (i & (1 << (n - 1))) != 0)
      continue;
    for (int b = 1; b <= n; b++) {
      // 剪枝非必要，全 1 时，只需要求b=n即可
      if (i == ((1 << n) - 1) && b != n)
        continue;
      // 第 b 位是1
      if ((i & (1 << (b - 1))) != 0) {
        int prev = i - (1 << (b - 1));
        for (auto a : inAdj[b]) {
          // 第 a 位是 1
          if ((i & (1 << (a - 1))) != 0) {
            dp[i][b] += dp[prev][a];
            dp[i][b] %= MOD;
          }
        }
      }
    }
  }
  cout << dp[(1 << n) - 1][n] << endl;
  return 0;
}