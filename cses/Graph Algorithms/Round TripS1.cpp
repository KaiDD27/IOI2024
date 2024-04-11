// dfs确保了cycleStart是cycle里面最靠近树根的节点，这样path就比较容易打印出来，相对于bfs.
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

vector<vector<int>> adj;
vector<int> pre;
vector<bool> visited;
vector<int> cycle;
int cycleStart = 0, cycleEnd = 0;

bool dfs(int i, int prevI) {
  visited[i] = true;
  pre[i] = prevI;
  for (auto ai : adj[i]) {
    if (visited[ai] && ai != pre[i]) {
      cycleStart = ai;
      cycleEnd = i;
      return true;
    } else if (!visited[ai]) {
      if (dfs(ai, i))
        return true;
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  pre.resize(n + 1);
  adj.resize(n + 1);
  visited.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[b].push_back(a);
    adj[a].push_back(b);
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      if (dfs(i, 0)) {
        break;
      }
    }
  }
  if (cycleStart == 0)
    cout << "IMPOSSIBLE" << endl;
  else {
    cycle.push_back(cycleStart);
    while (cycleEnd != cycleStart) {
      cycle.push_back(cycleEnd);
      cycleEnd = pre[cycleEnd];
    }
    cycle.push_back(cycleStart);
    cout << cycle.size() << endl;
    for (auto ci : cycle)
      cout << ci << " ";
  }
  return 0;
}