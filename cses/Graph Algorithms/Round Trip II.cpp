// dfs，关键是用三种状态来区分，未访问，访问中，访问结束，遇到访问中则是找到环
// 题目已经排除长度为 1的环
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> adj;
vector<int> visited; // 0未访问，1访问中，2访问结束
vector<int> pre;
int cycleStart = -1, cycleFin = -1;
bool dfs(int a) {
  visited[a] = 1;
  for (auto b : adj[a]) {
    if (visited[b] == 2) {
      continue;
    } else if (visited[b] == 1) {
      cycleStart = a;
      cycleFin = b;
      return true;
    } else if (visited[b] == 0) {
      pre[b] = a;
      if (dfs(b) == true)
        return true;
    }
  }
  visited[a] = 2;
  return false;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  visited.resize(n + 1, 0);
  pre.resize(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      if (dfs(i) == true)
        break;
    }
  }
  if (cycleStart == -1)
    cout << "IMPOSSIBLE" << endl;
  else {
    vector<int> cycle;
    int tmp = cycleStart;
    while (tmp != cycleFin) {
      cycle.push_back(tmp);
      tmp = pre[tmp];
    }
    cycle.push_back(cycleFin);
    cycle.push_back(cycleStart);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << endl;
    for (auto ci : cycle)
      cout << ci << " ";
  }
  return 0;
}