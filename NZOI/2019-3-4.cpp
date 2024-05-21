#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, p, s, e;
vector<ll> dist;
vector<bool> processed;
vector<vector<ll>> adj;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> p >> s >> e;
  adj.resize(n);
  dist.resize(n, LLONG_MAX);
  processed.resize(n, false);
  for (int i = 0; i < p; i++) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  // dijkstra
  priority_queue<array<ll, 2>> pq;
  dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    auto a = pq.top()[1];
    pq.pop();
    processed[a] = true;
    for (auto b : adj[a]) {
      if (processed[b] == true) {
        continue;
      }
      if (dist[b] > dist[a] + 1) {
        dist[b] = dist[a] + 1;
        pq.push({-dist[b], b});
      }
    }
  }
  cout << dist[e] << endl;
  return 0;
}