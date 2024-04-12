// 参考解题思路 https://usaco.guide/problems/cses-1195-flight-discount/solution
// Solution 2
#include <climits>
#include <iostream>
#include <queue>
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
  priority_queue<array<ll, 3>> pq;
  pq.push({0, 1, 0});

  return 0;
}