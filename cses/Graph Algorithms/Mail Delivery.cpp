#include <array>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<bool> streetVisited;
vector<stack<pair<int, int>>> adj;
queue<int> q;
void dfs(int a) {
  while (!adj[a].empty()) {
    auto [b, e] = adj[a].top();
    // 每条边只需要处理一次，这样可以优化大 O
    adj[a].pop();
    if (streetVisited[e] == false) {
      streetVisited[e] = true;
      dfs(b);
    }
  }
  q.push(a);
  return;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  streetVisited.resize(m);
  adj.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push({b, i});
    adj[b].push({a, i});
  }
  for (int i = 1; i <= n; i++)
    if (adj[i].size() % 2 == 1) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }

  dfs(1);
  if (q.size() != m + 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}