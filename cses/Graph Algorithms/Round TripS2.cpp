// bfs逐层扫描导致cycleStart不一定是depth最高的，所以找path比较麻烦
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"

vector<vector<int>> adj;
vector<int> pre;
vector<int> depth;
vector<int> cycle;
vector<int> pathOfStart, pathOfFin;
int cycleStart = 0, cycleFin = 0;

bool bfs(int start) {
  queue<int> q;
  q.push(start);
  depth[start] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (v == pre[u])
        continue; // 跳过父节点
      if (depth[v] >= 0) {
        cycleStart = v;
        cycleFin = u;
        return true;
      }
      q.push(v);
      pre[v] = u;
      depth[v] = depth[u] + 1;
    }
  }
  return false;
}
void printPath(int start, int fin) {
  while (start != 0) {
    pathOfStart.push_back(start);
    start = pre[start];
  }
  reverse(pathOfStart.begin(), pathOfStart.end());
  while (fin != 0) {
    pathOfFin.push_back(fin);
    fin = pre[fin];
  }
  reverse(pathOfFin.begin(), pathOfFin.end());
  int begin = 0;
  for (int i = 0; i < pathOfFin.size() && i < pathOfStart.size(); i++) {
    if (pathOfStart[i] != pathOfFin[i])
      break;
    begin = i;
  }
  for (int i = begin; i < pathOfFin.size(); i++)
    cycle.push_back(pathOfFin[i]);
  for (int i = pathOfStart.size() - 1; i >= 0; i--) {
    cycle.push_back(pathOfStart[i]);
    if (pathOfStart[i] == pathOfStart[begin])
      break;
  }
  cout << cycle.size() << endl;
  for (auto ci : cycle)
    cout << ci << " ";
  return;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  pre.resize(n + 1);
  adj.resize(n + 1);
  depth.resize(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[b].push_back(a);
    adj[a].push_back(b);
  }
  for (int i = 1; i <= n; i++) {
    if (depth[i] == -1) {
      if (bfs(i) == true)
        break;
    }
  }

  if (cycleStart == 0)
    cout << "IMPOSSIBLE" << endl;
  else {
    printPath(cycleStart, cycleFin);
  }
  return 0;
}