#include <algorithm>
#include <array>
#include <climits>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll m, r;
vector<ll> mCnt;
vector<pair<ll, vector<pair<ll, ll>>>> raft;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> m >> r;
  mCnt.resize(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> mCnt[i];
  }
  raft.resize(m + r + 1);
  for (int i = m + 1; i <= m + r; i++) {
    cin >> raft[i].first;
    raft[i].second.resize(raft[i].first);
    for (auto &[ti, ai] : raft[i].second) {
      cin >> ti >> ai;
    }
  }
  vector<ll> lastRaftNeed(m + r + 1, 0);
  lastRaftNeed[m + r] = 1;
  for (int i = m + r; i > m; i--) {
    if (lastRaftNeed[i] == 0)
      continue;
    for (auto [ti, ai] : raft[i].second) {
      lastRaftNeed[ti] += ai * lastRaftNeed[i];
    }
  }
  ll ans = LONG_MAX;
  for (int i = 1; i <= m; i++) {
    if (lastRaftNeed[i] != 0)
      ans = min(ans, mCnt[i] / lastRaftNeed[i]);
  }
  cout << ans << endl;
  return 0;
}