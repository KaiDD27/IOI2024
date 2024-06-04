#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, a, b;
vector<ll> days;
vector<ll> preSum;
map<ll, ll> mpPreSumToIdx;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> a >> b;
  days.resize(n + 1);
  // 0做为墙
  preSum.resize(n + 1);

  // 降噪，二值化，简化数据
  for (int i = 1; i <= n; i++) {
    cin >> days[i];
    if (days[i] < a || days[i] > b)
      days[i] = -1;
    else
      days[i] = 1;
    preSum[i] = preSum[i - 1] + days[i];
  }
  // 区间和大于 0 就是满足要求的，用到单调 map，以 preSum 为key,以下标为 value
  mpPreSumToIdx[0] = 0;
  ll maxLength = 0;
  for (int i = 1; i <= n; i++) {
    auto it = mpPreSumToIdx.lower_bound(preSum[i]);
    if (it != mpPreSumToIdx.begin()) {
      it--;
      maxLength = max(maxLength, i - it->second);
    }
    if (preSum[i] < mpPreSumToIdx.begin()->first) {
      mpPreSumToIdx[preSum[i]] = i;
    }
  }
  cout << maxLength << endl;
  return 0;
}