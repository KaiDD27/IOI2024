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
    inAdj[--b].push_back(--a);
  }
  dp[1][0] = 1;
  for (int i = 2; i < 1 << n; i++) {
    if ((i & (1 << 0)) == 0)
      continue;
    if ((i & (1 << (n - 1))) && i != ((1 << n) - 1))
      continue;
    for (int b = 0; b < n; b++) {
      if ((i & (1 << b)) == 0)
        continue;
      int prev = i - (1 << b);
      // 第 b 位是1
      for (auto a : inAdj[b]) {
        // 第 a 位是 1
        if ((i & (1 << a)) != 0) {
          dp[i][b] += dp[prev][a];
          dp[i][b] %= MOD;
        }
      }
    }
  }
  cout << dp[(1 << n) - 1][n - 1] << endl;
  return 0;
}
