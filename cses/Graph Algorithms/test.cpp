#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;

int cycleStart = -1, cycleEnd = -1;

bool dfs(int u, int par) {
  visited[u] = true;
  parent[u] = par;

  for (int v : adj[u]) {
    if (v == par)
      continue; // 跳过父节点
    if (visited[v]) {
      cycleStart = v;
      cycleEnd = u;
      return true;
    }
    if (dfs(v, u))
      return true;
  }

  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  parent.resize(n + 1);
  visited.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i] && dfs(i, -1))
      break;
  }

  if (cycleStart == -1) {
    cout << "IMPOSSIBLE\n";
  } else {
    vector<int> cycle;
    cycle.push_back(cycleStart);
    for (int v = cycleEnd; v != cycleStart; v = parent[v])
      cycle.push_back(v);
    cycle.push_back(cycleStart);

    cout << cycle.size() << "\n";
    for (int v : cycle)
      cout << v << " ";
    cout << "\n";
  }

  return 0;
}