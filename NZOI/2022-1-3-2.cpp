#include <algorithm>
#include <array>
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
  mpPreSumToIdx[0] = 0;
  // 降噪，二值化，简化数据
  for (int i = 1; i <= n; i++) {
    cin >> days[i];
    if (days[i] < a || days[i] > b)
      days[i] = -1;
    else
      days[i] = 1;
    preSum[i] = preSum[i - 1] + days[i];
    // 只有之前的最小的小，才有放进map的价值
    if (preSum[i] < mpPreSumToIdx.begin()->first) {
      mpPreSumToIdx[preSum[i]] = i;
    }
  }
  ll maxLength = 0;
  for (int i = 1; i <= n; i++) {
    auto it = mpPreSumToIdx.lower_bound(preSum[i]);
    if (it != mpPreSumToIdx.begin()) {
      it--;
      maxLength = max(maxLength, i - it->second);
    }
  }
  cout << maxLength << endl;
  return 0;
}