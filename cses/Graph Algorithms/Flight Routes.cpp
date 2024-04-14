#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

vector<vector<pair<int, int>>> adj;
vector<priority_queue<ll>> distCost;
priority_queue<pair<ll, int>> pq;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m, k;
  cin >> n >> m >> k;
  adj.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }
  distCost.resize(n + 1);
  distCost[1].push(0);
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [cost, city] = pq.top();
    pq.pop();
    if (distCost[city].size() >= k && -cost > distCost[city].top())
      continue;
    for (auto [b, c] : adj[city]) {
      ll tmp = -cost + c;
      if (distCost[b].size() < k) {
        distCost[b].push(tmp);
        pq.push({-tmp, b});
      } else if (tmp < distCost[b].top()) {
        distCost[b].pop();
        distCost[b].push(tmp);
        pq.push({-tmp, b});
      }
      /*即使==k 了，也有可能找出更短的路径，所以不能 break
            if (distCost[n].size() >= k)
              break;*/
    }
  }
  vector<ll> ans;
  while (!distCost[n].empty() && ans.size() != k) {
    ans.push_back(distCost[n].top());
    distCost[n].pop();
  }
  reverse(ans.begin(), ans.end());
  for (auto ai : ans)
    cout << ai << " ";
  return 0;
}