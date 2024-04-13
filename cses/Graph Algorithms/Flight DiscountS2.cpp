// 参考解题思路 https://usaco.guide/problems/cses-1195-flight-discount/solution
// Solution 2
#include <climits>
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<ll>> distCost;
vector<vector<pair<int, int>>> adj;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  // 第二维 第0个位置 代表没有用优惠券的最小费用，第1个位置
  // 代表用了优惠券最小费用
  distCost.resize(n + 1, vector<ll>(2, LLONG_MAX));
  adj.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }
  // 0位代表 -dist，1 代表city，2 是否用过了优惠券
  distCost[1][0] = 0;
  priority_queue<tuple<ll, int, bool>> pq;
  pq.push({0, 1, false});
  while (!pq.empty()) {
    auto [tmpMinDistance, city, used] = pq.top();
    pq.pop();
    if (used == false && -tmpMinDistance != distCost[city][0])
      continue;
    if (used == true && -tmpMinDistance != distCost[city][1])
      continue;
    // 剪枝。其实不剪枝也没问题
    if (city == n)
      break;
    for (auto [otherCity, cost] : adj[city]) {
      // 如果在前序没有用过coupon，本次可以用
      if (used == false &&
          distCost[otherCity][1] > -tmpMinDistance + cost / 2) {
        distCost[otherCity][1] = -tmpMinDistance + cost / 2;
        pq.push({-distCost[otherCity][1], otherCity, true});
      }
      // 不管前序用没用过
      // coupon，本次不用优惠券,继承目前是否用过优惠券的状态就好
      if (distCost[otherCity][used] > -tmpMinDistance + cost) {
        distCost[otherCity][used] = -tmpMinDistance + cost;
        pq.push({-distCost[otherCity][used], otherCity, used});
      }
    }
  }
  cout << distCost[n][1] << endl;
  return 0;
}
