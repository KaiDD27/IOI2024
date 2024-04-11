// 逐一计算单点到所有的最短路径，O（n(n+mlogm)），因为 m 可以为n2所以超时
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
const ll INF = 1e14 + 10;
vector<vector<pair<int, int>>> adj;
vector<bool> processed;
vector<vector<ll>> dist;
vector<pair<int, int>> query;
void shortestRoute(int x) {
  priority_queue<pair<ll, int>> pq;
  fill(processed.begin(), processed.end(), false);
  dist[x][x] = 0;
  pq.push({0, x});
  while (!pq.empty()) {
    int a = pq.top().second;
    pq.pop();
    if (processed[a] == true)
      continue;
    processed[a] = true;
    for (auto ai : adj[a]) {
      int b = ai.first;
      ll w = ai.second;
      if (dist[x][a] + w < dist[x][b]) {
        dist[x][b] = dist[x][a] + w;
        pq.push({-dist[x][b], b});
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m, q;
  cin >> n >> m >> q;
  adj.resize(n + 1);
  dist.resize(n + 1, vector<ll>(n + 1, INF));
  processed.resize(n + 1, false);
  query.resize(q);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  for (auto &qi : query) {
    cin >> qi.first >> qi.second;
  }
  for (int i = 1; i <= n; i++)
    shortestRoute(i);
  for (auto qi : query) {
    if (dist[qi.first][qi.second] == INF)
      cout << "-1" << endl;
    else
      cout << dist[qi.first][qi.second] << endl;
  }
  return 0;
}