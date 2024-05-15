#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<array<int, 2>>> adj;
vector<vector<int>> dp;
vector<int> sumEdge;
int n, q;
void dfs(int a, int father) {
  for (auto [b, c] : adj[a]) {
    if (b == father)
      continue;
    dfs(b, a);
    sumEdge[a] += (sumEdge[b] + 1);
    // i必须从大到小，因为这样才可以保证转移到之前其他子树算出来的结果
    for (int i = min(sumEdge[a], q); i >= 1; i--) {
      for (int k = 0; k <= min(i - 1, sumEdge[b]); k++) {
        // dp[a][i - k - 1]是之前其他已经计算过的子树最优的结果
        dp[a][i] = max(c + dp[b][k] + dp[a][i - k - 1], dp[a][i]);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> q;
  adj.resize(n + 1, vector<array<int, 2>>());
  dp.resize(n + 1, vector<int>(q + 1, 0));
  sumEdge.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  dfs(1, 0);
  cout << dp[1][q] << endl;
  return 0;
}