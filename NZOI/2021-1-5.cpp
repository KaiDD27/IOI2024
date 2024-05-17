#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<array<ll, 3>> students;
// 已消耗的 lSum,rSum的组合可以得到的最大total happiness
vector<map<pair<ll, ll>, ll>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll l, r, n;
  cin >> l >> r >> n;
  students.resize(n + 1);
  // 按照 ci 升序排列有利于让不合理的分配尽早出局，优化常数时间，不是必需的优化
  sort(students.begin(), students.end(),
       [](array<ll, 3> &a, array<ll, 3> &b) { return a > b; });
  for (int i = 1; i <= n; i++) {
    cin >> students[i][0] >> students[i][1] >> students[i][2];
  }
  dp.resize(2);
  int now = 0, old = 1;
  // 初始化，左右消耗 total happiness 也是 0
  dp[now][{0, 0}] = 0;

  for (auto si : students) {
    swap(now, old);
    dp[now].clear();
    auto [ci, li, ri] = si;
    for (auto di : dp[old]) {
      auto [lSum, rSum] = di.first;
      auto totalHappiness = di.second;
      if (li != -1) {
        if ((lSum + ci) <= l) {
          dp[now][{lSum + ci, rSum}] =
              max(dp[now][{lSum + ci, rSum}], totalHappiness + li);
        }
      }
      if (ri != -1) {
        if ((rSum + ci) <= r) {
          dp[now][{lSum, rSum + ci}] =
              max(dp[now][{lSum, rSum + ci}], totalHappiness + ri);
        }
      }
    }
    if (dp[now].size() == 0) {
      cout << "Camp is cancelled" << endl;
      return 0;
    }
  }
  ll ans = 0;
  for (auto si : dp[now]) {
    ans = max(ans, si.second);
  }
  cout << ans << endl;
  return 0;
}