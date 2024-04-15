// 不能用拓扑排序，因为有环
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> adj;
vector<int> inAdjCnt;
vector<ll> dp;
const ll MOD = 1e9 + 7;
const ll INF = 1e15 + 10;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  inAdjCnt.resize(n + 1);
  dp.resize(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    inAdjCnt[b]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (inAdjCnt[i] == 0)
      q.push(i);
  }
  dp[1] = 1;
  while (!q.empty()) {
    auto a = q.front();
    q.pop();
    for (auto b : adj[a]) {
      dp[b] += dp[a];
      dp[b] %= MOD;
      if (--inAdjCnt[b] == 0)
        q.push(b);
    }
  }

  cout << dp[n] << endl;
  return 0;
}