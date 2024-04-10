// Bellman-Ford , 最低效的办法，可以处理有权图，但这题为无权图，不建议
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
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  edges.resize(m);
  dis.resize(n + 1, n + 1);
  for (auto &ei : edges) {
    cin >> ei.first >> ei.second;
  }
  dis[1] = 0;
  for (int i = 1; i <= n - 1; i++) {
    for (auto ei : edges) {
      dis[ei.first] = min(dis[ei.first], dis[ei.second] + 1);
      dis[ei.second] = min(dis[ei.second], dis[ei.first] + 1);
    }
  }
  if (dis[n] >= n + 1)
    cout << "IMPOSSIBLE" << endl;
  else {
    cout << dis[n] + 1 << endl;
    stack<int> path;
    path.push(n);
    while (n != 1) {
      for (auto ei : edges) {
        if (ei.first == n && dis[ei.second] == dis[n] - 1) {
          n = ei.second;
          path.push(n);
          break;
        }
        if (ei.second == n && dis[ei.first] == dis[n] - 1) {
          n = ei.first;
          path.push(n);
          break;
        }
      }
    }
    while (!path.empty()) {
      cout << path.top() << " ";
      path.pop();
    }
  }
  return 0;
}