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
int cycleStart = -1, cycleFin = -1;

bool dfs(int a) {
  visited[a] = true;
  for (auto b : adj[a]) {
    // 要注意排除掉自己的上一层
    if (visited[b] && b != pre[a]) {
      cycleStart = a;
      cycleFin = b;
      return true;
    } else if (!visited[b]) {
      pre[b] = a;
      if (dfs(b))
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
  pre.resize(n + 1, -1);
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
      if (dfs(i)) {
        break;
      }
    }
  }
  if (cycleStart == -1)
    cout << "IMPOSSIBLE" << endl;
  else {
    int tmp = cycleStart;
    while (tmp != cycleFin) {
      cycle.push_back(tmp);
      tmp = pre[tmp];
    }
    cycle.push_back(cycleFin);
    cycle.push_back(cycleStart);
    cout << cycle.size() << endl;
    for (auto ci : cycle)
      cout << ci << " ";
  }
  return 0;
}