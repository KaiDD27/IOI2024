// 先建立邻接表
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> adj;
vector<int> dis;
vector<int> prev;
void bfs(int i) {
  queue<int> q;
  q.push(i);
  dis[i] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto ai : adj[x]) {
      if (dis[ai] > dis[x] + 1) {
        dis[ai] = dis[x] + 1;
        q.push(ai);
        pre[ai] = x;
      }
    }
  }
}
void printPath(int x) {
  if (x == 0)
    return;
  printPath(prev[x]);
  cout << x << " ";
  return;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  dis.resize(n + 1, n + 1);
  prev.resize(n + 1);
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bfs(1);
  if (dis[n] >= n + 1)
    cout << "IMPOSSIBLE" << endl;
  else {
    cout << dis[n] + 1 << endl;
    printPath(n);
  }
  return 0;
}