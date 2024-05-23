#include <array>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll r, n, t;
vector<array<ll, 2>> costFuel;
vector<ll> s;
vector<vector<array<ll, 2>>> adj;
vector<ll> dist;
vector<bool> processed;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> r >> n >> t;
  costFuel.resize(r);
  s.resize(n);
  adj.resize(t);
  dist.resize(t, LLONG_MAX);
  processed.resize(t);
  for (auto &[ci, fi] : costFuel)
    cin >> ci >> fi;
  for (auto &si : s)
    cin >> si;
  for (int i = 0; i < t; i++) {
    for (auto [ci, fi] : costFuel) {
      if (i + fi < t)
        adj[i].push_back({i + fi, ci});
      adj[i].push_back({abs(i - fi), ci});
    }
  }
  // dijkstra 求0 到每一个节点的最短路径
  priority_queue<array<ll, 2>> pq;
  pq.push({0, 0});
  dist[0] = 0;
  while (!pq.empty()) {
    auto a = pq.top()[1];
    pq.pop();
    if (processed[a] == true)
      continue;
    processed[a] = true;
    for (auto [b, c] : adj[a]) {
      if (dist[a] + c < dist[b]) {
        dist[b] = dist[a] + c;
        pq.push({-dist[b], b});
      }
    }
  }
  for (auto si : s)
    cout << dist[si] << endl;
  return 0;
}