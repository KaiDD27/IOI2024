#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll n, k;
vector<ll> e, preSum, dp, ds;
deque<ll> dq;
ll que_max(ll j) {
  while (!dq.empty() && (dq.front() < j - k))
    dq.pop_front(); // 去掉超过窗口k的队头
  while (!dq.empty() &&
         (dp[dq.back() - 1] - preSum[dq.back()]) < (dp[j - 1] - preSum[j]))
    dq.pop_back(); // 去掉不合格的队尾
  dq.push_back(j); // j进队尾

  return (dp[dq.front() - 1] -
          preSum[dq.front()]); // 返回队头，即最大的dp[j-1]-sum[j]
}
int main() {
  cin >> n >> k;
  preSum.resize(n + 1);
  e.resize(n + 1);
  dp.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> e[i];
    preSum[i] = preSum[i - 1] + e[i]; // 计算前缀和
  }
  dq.push_back(0);
  for (int i = 1; i <= n; i++) {
    dp[i] = que_max(i) + preSum[i]; // 状态转移方程
  }
  cout << dp[n];
}