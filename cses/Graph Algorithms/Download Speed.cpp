// 最大流 Edmonds-Karp 算法，每轮都通过 bfs 找出最短增广路
#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> adj;
vector<vector<ll>> capacity;
vector<int> pre;
ll n, m;
// 最短的路径会先被找出来
bool bfs() {
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    auto a = q.front();
    q.pop();
    for (auto b : adj[a]) {
      if (capacity[a][b] > 0 && pre[b] == -1) {
        pre[b] = a;
        q.push(b);
      }
    }
  }
  return pre[n] != -1;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together

  cin >> n >> m;
  adj.resize(n + 1);
  capacity.resize(n + 1, vector<ll>(n + 1));
  pre.resize(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back(b);
    // 反向路线也要加入，因为残留网络需要对反向路径进行操作
    adj[b].push_back(a);
    //  允许有多条重复的路线，需要累计网速
    capacity[a][b] += c;
  }

  ll maxFlow = 0;
  while (bfs()) {
    int b = n;
    ll currFlow = LLONG_MAX;
    while (b != 1) {
      int a = pre[b];
      currFlow = min(currFlow, capacity[a][b]);
      b = a;
    }
    b = n;
    while (b != 1) {
      int a = pre[b];
      capacity[a][b] -= currFlow;
      capacity[b][a] += currFlow;
      b = a;
    }
    maxFlow += currFlow;
    fill(pre.begin(), pre.end(), -1);
  }
  cout << maxFlow << endl;
  return 0;
}