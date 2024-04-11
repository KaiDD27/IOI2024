// 用adj
#include <array>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
const ll INF = 1e15;
vector<vector<pair<int, int>>> adj;
vector<ll> dist;
vector<bool> visited;

bool dfs(int u, int n) {
  if (u == n)
    return true;
  visited[u] = true;
  for (auto [b, x] : adj[u]) {
    if (visited[b] == false && dfs(b, n))
      return true;
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, x;
    cin >> a >> b >> x;
    adj[a].push_back({b, x});
  }

  dist.resize(n + 1, -INF);
  dist[1] = 0;

  for (int i = 1; i < n; i++) {
    for (int a = 1; a <= n && adj[a].size() != 0; a++) {
      for (auto [b, x] : adj[a]) {
        if (dist[a] != -INF && dist[a] + x > dist[b]) {
          dist[b] = dist[a] + x;
        }
      }
    }
  }

  // 检测从 1 到 n 的路径上是否存在正环
  visited.resize(n + 1, false);
  // 检测从 1 到 n 的路径上是否存在正环
  for (int a = 1; a <= n && adj[a].size() != 0; a++) {
    for (auto [b, x] : adj[a]) {
      if (dist[a] != -INF && dist[a] + x > dist[b]) {
        // 从 b 开始 DFS，检查 n 是否可达
        if (dfs(b, n)) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }

  cout << (dist[n] == LLONG_MIN ? -1 : dist[n]) << endl;
  return 0;
}