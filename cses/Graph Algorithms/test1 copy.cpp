#include <array>
#include <climits>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const long long INF = 1e18;

int main() {
  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++) {
    int a, b, x;
    cin >> a >> b >> x;
    edges.emplace_back(a, b, x);
  }

  vector<long long> dist(n + 1, -INF);
  dist[1] = 0;

  for (int i = 1; i < n; i++) {
    for (auto [a, b, x] : edges) {
      if (dist[a] != -INF)
        dist[b] = max(dist[b], dist[a] + x);
    }
  }

  // 检测从 1 到 n 的路径上是否存在正环
  for (auto [a, b, x] : edges) {
    if (dist[a] != -INF && dist[a] + x > dist[b]) {
      // 从 b 开始 DFS，检查 n 是否可达
      vector<bool> vis(n + 1, false);
      function<bool(int)> dfs = [&](int u) {
        if (u == n)
          return true;
        if (vis[u])
          return false;
        vis[u] = true;
        for (auto [a, b, x] : edges) {
          if (a == u && dfs(b))
            return true;
        }
        return false;
      };
      if (dfs(b)) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  cout << (dist[n] == -INF ? -1 : dist[n]) << endl;
  return 0;
}