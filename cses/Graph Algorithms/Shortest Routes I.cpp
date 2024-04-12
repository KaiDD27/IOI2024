// Dijkstra通过将距离乘以 -1，用优先队列默认的最大堆，注意one-way flight
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
const ll INF = 1e14 + 10;
vector<vector<pair<int, int>>> adj;
vector<ll> dist;
priority_queue<pair<ll, int>> pq;
vector<bool> processed;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  dist.resize(n + 1, INF);
  adj.resize(n + 1);
  processed.resize(n + 1, false);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  dist[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [shortestDistance, a] = pq.top();
    pq.pop();
    // 这个可以替代processed的效果，且节省了空间
    // 当不是最短距离时，说明之前已经处理过了，这个直接跳过就好
    if (-shortestDistance != dist[a])
      continue;
    for (auto ai : adj[a]) {
      int b = ai.first, w = ai.second;
      if (dist[a] + w < dist[b]) {
        dist[b] = dist[a] + w;
        pq.push({-dist[b], b});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }
  return 0;
}