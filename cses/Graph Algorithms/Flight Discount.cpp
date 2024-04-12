// 参考解题思路 https://usaco.guide/problems/cses-1195-flight-discount/solution
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> distStartCost, distFinCost;
vector<vector<pair<int, int>>> adj, inAdj;

// Dijkstra 求从起点到任何节点的最短路径，或者求从任何节点到终点的最短路径
void minCost(int sOrFcity, vector<vector<pair<int, int>>> &adjOrInAdj,
             vector<ll> &distCost) {
  priority_queue<pair<ll, int>> pq;
  vector<bool> processed(distCost.size(), false);
  distCost[sOrFcity] = 0;
  pq.push({0, sOrFcity});
  while (!pq.empty()) {
    int city = pq.top().second;
    pq.pop();
    if (processed[city] == true)
      continue;
    processed[city] = true;
    for (auto [otherCity, cost] : adjOrInAdj[city]) {
      if (distCost[otherCity] > distCost[city] + cost) {
        distCost[otherCity] = distCost[city] + cost;
        pq.push({-distCost[otherCity], otherCity});
      }
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  distStartCost.resize(n + 1, LLONG_MAX);
  distFinCost.resize(n + 1, LLONG_MAX);
  adj.resize(n + 1);
  inAdj.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    inAdj[b].push_back({a, c});
  }
  minCost(1, adj, distStartCost);
  minCost(n, inAdj, distFinCost);
  ll ans = LLONG_MAX;
  // 遍历每一条边使用促销，然后求最小的
  for (int fromCity = 1; fromCity <= n; fromCity++) {
    for (auto [toCity, cost] : adj[fromCity]) {
      if (distStartCost[fromCity] == LLONG_MAX ||
          distFinCost[toCity] == LLONG_MAX)
        continue;
      ans = min(ans, distStartCost[fromCity] + cost / 2 + distFinCost[toCity]);
    }
  }
  cout << ans << endl;
  return 0;
}