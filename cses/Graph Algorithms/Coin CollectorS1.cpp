// Kosaraju找 SCC，然后记忆化搜索递归
#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> coinNum, roomScc;
vector<ll> sccCoin, dp;
vector<bool> visited;
vector<vector<int>> adj, rAdj, sccReverseadj;
stack<int> sk;
int sccLabel = 0;
void dfs(int a) {
  visited[a] = true;
  for (auto b : adj[a])
    if (visited[b] == false)
      dfs(b);
  sk.push(a);
  return;
}
void rDfs(int a) {
  roomScc[a] = sccLabel;
  sccCoin[sccLabel] += coinNum[a];
  for (auto b : rAdj[a])
    if (roomScc[b] == -1)
      rDfs(b);
  return;
}
// 记忆化搜索
ll dfsScc(int sccA) {
  if (dp[sccA] != 0)
    return dp[sccA];
  dp[sccA] = sccCoin[sccA];
  for (auto sccB : sccReverseadj[sccA]) {
    dp[sccA] = max(dp[sccA], sccCoin[sccA] + dfsScc(sccB));
  }
  return dp[sccA];
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  coinNum.resize(n + 1);
  adj.resize(n + 1);
  rAdj.resize(n + 1);
  roomScc.resize(n + 1, -1);
  // 最多只可能有 n 个scc
  sccCoin.resize(n + 1);
  dp.resize(n + 1);
  sccReverseadj.resize(n + 1);
  visited.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> coinNum[i];

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    rAdj[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i] == false)
      dfs(i);
  }

  while (!sk.empty()) {
    if (roomScc[sk.top()] == -1) {
      sccLabel++;
      rDfs(sk.top());
    }
    sk.pop();
  }

  for (int a = 1; a <= n; a++) {
    for (auto b : adj[a]) {
      if (roomScc[a] != roomScc[b]) {
        sccReverseadj[roomScc[a]].push_back(roomScc[b]);
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= sccLabel; i++) {
    if (dp[i] == 0)
      dp[i] = dfsScc(i);
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}