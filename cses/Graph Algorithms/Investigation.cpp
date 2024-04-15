// 不能用拓扑排序，因为有环.
// dijkstra可以确保 距离起点越近的点越先标记,虽然被 push
// 到优先队列了，但是不会在距离更近的点弹出之前先弹出，并且在队列中时，还可能会有次节点更短的距离被
// push 进来，会让之前的那次 push 被忽略，因为他不等于当前最短距离了
// visited=true，所以不会遗漏统计多条相等的最短路径的数量
#include <algorithm>
#include <array> // Include the missing header file
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll INF = 1e15 + 10;
vector<vector<pair<int, int>>> adj;
// 0 miniPrice,1 routeCnt,2 minFlightsNum, 3 maxFlightNum
vector<array<ll, 4>> dp;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;

  adj.resize(n + 1);
  dp.resize(n + 1, {INF, 0, INF, 0});

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  priority_queue<pair<ll, int>> pq;
  dp[1] = {0, 1, 0, 0};
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [minPriceOfA, a] = pq.top();
    pq.pop();
    // 大于则说明后来又有更短的距离数据进来了，这条数据就没有用了
    if (-minPriceOfA > dp[a][0])
      continue;
    for (auto [b, c] : adj[a]) {
      if (dp[b][0] == dp[a][0] + c) {
        dp[b][1] += dp[a][1];
        dp[b][1] %= MOD;
        dp[b][2] = min(dp[b][2], dp[a][2] + 1);
        dp[b][3] = max(dp[b][3], dp[a][3] + 1);
      } else if (dp[b][0] > dp[a][0] + c) {
        dp[b][0] = dp[a][0] + c;
        dp[b][1] = dp[a][1];
        dp[b][1] %= MOD;
        dp[b][2] = dp[a][2] + 1;
        dp[b][3] = dp[a][3] + 1;
        pq.push({-dp[b][0], b});
      }
    }
  }

  for (auto m : dp[n])
    cout << m << " ";

  return 0;
}