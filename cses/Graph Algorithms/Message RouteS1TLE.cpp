// 无权图，用 bfs 就可以了，并通过 pre 来记住前驱节点，最后递归打印即可。
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<pair<int, int>> edges;
vector<int> dis;
vector<int> pre;
void bfs(int i) {
  queue<int> q;
  q.push(i);
  dis[i] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto ei : edges) {
      if (ei.first == x && dis[ei.second] > dis[x] + 1) {
        dis[ei.second] = dis[x] + 1;
        pre[ei.second] = x;
        q.push(ei.second);
      }
      if (ei.second == x && dis[ei.first] > dis[x] + 1) {
        dis[ei.first] = dis[x] + 1;
        pre[ei.first] = x;
        q.push(ei.first);
      }
    }
  }
}
void printPath(int x) {
  if (x == 0)
    return;
  printPath(pre[x]);
  cout << x << " ";
  return;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  edges.resize(m);
  dis.resize(n + 1, n + 1);
  pre.resize(n + 1);
  for (auto &ei : edges) {
    cin >> ei.first >> ei.second;
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