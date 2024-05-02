#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<array<ll, 3>> students;
vector<map<pair<ll, ll>, ll>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll l, r, n;
  cin >> l >> r >> n;
  students.resize(n + 1);
  dp.resize(2);
  for (int i = 1; i <= n; i++) {
    cin >> students[i][0] >> students[i][1] >> students[i][2];
  }
  int now = 0, old = 1;
  dp[now][{0, 0}] = 0;

  for (int i = 1; i <= n; i++) {
    swap(now, old);
    dp[now].clear();
    ll ci = students[i][0];
    ll li = students[i][1];
    ll ri = students[i][2];
    for (auto si : dp[old]) {
      auto [lSum, rSum] = si.first;
      auto totalHappiness = si.second;
      if (li != -1) {
        if ((lSum + ci) <= l) {
          if (dp[now].count({lSum + ci, rSum})) {
            dp[now][{lSum + ci, rSum}] =
                max(dp[now][{lSum + ci, rSum}], totalHappiness + li);
          } else
            dp[now][{lSum + ci, rSum}] = totalHappiness + li;
        }
      }
      if (ri != -1) {
        if ((rSum + ci) <= r) {
          if (dp[now].count({lSum, rSum + ci})) {
            dp[now][{lSum, rSum + ci}] =
                max(dp[now][{lSum, rSum + ci}], totalHappiness + ri);
          } else
            dp[now][{lSum, rSum + ci}] = totalHappiness + ri;
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