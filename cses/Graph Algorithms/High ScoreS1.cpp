#include <array>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<array<int, 3>> edges;
const ll INF = 1e15;
vector<ll> dist;
vector<bool> visited;

bool dfs(int u, int n) {
  if (u == n)
    return true;
  visited[u] = true;
  for (auto [a, b, x] : edges) {
    if (a == u && visited[b] == false && dfs(b, n))
      return true;
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  edges.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
  }

  dist.resize(n + 1, -INF);
  dist[1] = 0;

  for (int i = 1; i < n; i++) {
    for (auto [a, b, x] : edges) {
      if (dist[a] != -INF && dist[a] + x > dist[b]) {
        dist[b] = dist[a] + x;
      }
    }
  }
  visited.resize(n + 1, false);
  // 检测从 1 到 n 的路径上是否存在正环
  for (auto [a, b, x] : edges) {
    if (dist[a] != -INF && dist[a] + x > dist[b]) {
      // 从 b 开始 DFS，检查 n 是否可达
      if (dfs(b, n)) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  cout << (dist[n] == -INF ? -1 : dist[n]) << endl;
  return 0;
}
